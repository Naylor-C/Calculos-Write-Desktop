#include <gtk/gtk.h>


void subFrame(GtkApplication* app, gpointer   user_data)
{

GtkWidget *window;

window = gtk_application_window_new (app);
gtk_window_set_title (GTK_WINDOW (window), "Calculos-Write");
gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
gtk_window_present (GTK_WINDOW (window));

}