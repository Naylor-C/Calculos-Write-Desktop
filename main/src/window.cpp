#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();

protected:
  //Signal handlers:
  void on_start_clicked();
  void on_button1_clicked();
  void on_button2_clicked();


 Gtk::AspectFrame F_Aspect;

  //Child widgets:
  Gtk::Frame subFrame, F_Drawing;

  //Member widgets:
  Gtk::Button button0, button1, button2;

  Gtk::DrawingArea m_DrawingArea;
};

MyWindow::MyWindow()
{
  set_title("Math-Write");
  set_default_size(800, 600);

}

//BUTTONS
MyWindow::MyWindow()
: button0("Start")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  button0.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  button0.signal_clicked().connect(sigc::mem_fun(*this,
              &MyWindow::on_start_clicked));

  // This packs the button into the Window (a container).
  set_child(button0);
}


MMyWindow::MyWindow()
: button1("Option")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  button1.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  button1.signal_clicked().connect(sigc::mem_fun(*this,
              &MyWindow::on_button1_clicked));

  // This packs the button into the Window (a container).
  set_child(button1);
}


MyWindow::MyWindow()
: button2("Quit")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  button2.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  button2.signal_clicked().connect(sigc::mem_fun(*this,
              &MyWindow::on_button2_clicked));

  // This packs the button into the Window (a container).
  set_child(button2);
}

//Buttons

//Conteudo//
MyWindow::MyWindow()
: F_Aspect(
    Gtk::Align::CENTER, /* center x */
    Gtk::Align::CENTER, /* center y */
    2.0, /* xsize/ysize = 2 */
    false /* ignore child's aspect */),
F_Drawing("2x1" /* label */)
{
  set_title("Aspect Frame");

  // Set a child widget to the aspect frame */
  // Ask for a 200x200 window, but the AspectFrame will give us a 200x100
  // window since we are forcing a 2x1 aspect ratio */
  m_DrawingArea.set_content_width(200);
  m_DrawingArea.set_content_height(200);
  F_Drawing.set_child(m_DrawingArea);
  m_AspectFrame.set_child(m_Frame);
  m_AspectFrame.set_margin(10);

  // Add the aspect frame to our toplevel window:
  set_child(F_Drawing);
}



//Events 
void MyWindow:: on_start_clicked()
{
/* Sets the margin around the frame. */
  SubFrame.set_margin(10);

  set_child(SubFrame);

  /* Set the frames label */
  SubFrame.set_label("Gtk::Frame Widget");

  /* Align the label at the right of the frame */
  SubFrame.set_label_align(Gtk::Align::END);
}


int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}
