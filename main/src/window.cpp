#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button button0, button1, button2;

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
              &MyWindow::on_button_clicked));

  // This packs the button into the Window (a container).
  set_child(button0);
}


MMyWindow::MyWindow()
: button1("Start")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  button1.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  button1.signal_clicked().connect(sigc::mem_fun(*this,
              &MyWindow::on_button_clicked));

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
              &MyWindow::on_button_clicked));

  // This packs the button into the Window (a container).
  set_child(button2);
}

//Buttons



int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}
