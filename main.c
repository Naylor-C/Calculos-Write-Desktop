#include <gtk/gtk.h>

static void activate (GtkApplication* app, pointer  user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;

  //Configuraçoes da Janela//
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Calculos Write");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 800);
  gtk_window_present (GTK_WINDOW (window));

  //Configuraçoes do Box//
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

  
  //Configuraçoes do Botão//
  button = gtk_button_new_with_label ("Start Calculos");
  gtk_widget_set_halign (button, GTK_ALIGN_CENTER);

  //if button is clicked// 
  g_signal_connect (button, "clicked", G_CALLBACK (App), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);
  gtk_box_append (GTK_BOX (box), button);

  
  gtk_window_present (GTK_WINDOW (window));
}



void static App (GtkApplication *app, gpointer user_data) 
{

static void
draw_function (GtkDrawingArea *area,
               cairo_t        *cr,
               int             width,
               int             height,
               gpointer        data)
{
  GdkRGBA color;

  cairo_arc (cr,
             width / 2.0, height / 2.0,
             MIN (width, height) / 2.0,
             0, 2 * G_PI);

  gtk_widget_get_color (GTK_WIDGET (area),
                        &color);
  gdk_cairo_set_source_rgba (cr, &color);

  cairo_fill (cr);
}

int
main (int argc, char **argv)
{
  gtk_init ();

  GtkWidget *area = gtk_drawing_area_new ();
  gtk_drawing_area_set_content_width (GTK_DRAWING_AREA (area), 100);
  gtk_drawing_area_set_content_height (GTK_DRAWING_AREA (area), 100);
  gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (area),
                                  draw_function,
                                  NULL, NULL);
  return 0;
}

  
}






int main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
