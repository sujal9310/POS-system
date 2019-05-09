#include "mainwindow.h"

mainwindow::mainwindow(){
QDesktopWidget *widget = new QDesktopWidget;
setMinimumHeight(768);
setMinimumWidth(1024);
QRect screenSize = widget->availableGeometry(widget->primaryScreen());
this->move(screenSize.height()/2,screenSize.width()/8);
add_menus();
primarylayout->setMenuBar(menubar);
this->setLayout(primarylayout);
this->setWindowTitle("Point of Sale");
}

void mainwindow::add_menus(){
add_acts();
menubar->addMenu(file);
menubar->addMenu(help);
}

void mainwindow::add_acts(){
    about_us.setText("About");
    users.setText("Users");
    exit_program->setToolTip("Exit Program");
    exit_program->setText("Quit");
    file->addAction(exit_program);
    help->addAction(&users);
    help->addAction(&about_us);

    action_definations();
}

void mainwindow::action_definations(){
    connect(exit_program,&QAction::triggered,[=](){
    qDebug() << "Exiting Application.";
    exit(0);
    });

    connect(&about_us,&QAction::triggered,[=](){
    launch_about();
    });
}

void mainwindow::launch_about(){
    QDialog *dialog = new QDialog;
    QLabel *text = new QLabel();
    text->setText("Designed and developed by<br /> Ajinkya,<br />Sandesh,<br />Vijay,<br />Siddhant and <br /> Sujal <br />for Computer Science Project 1.");
    QHBoxLayout hbox;
    hbox.addWidget(text);
    dialog->setWindowTitle("About");
    dialog->setLayout(&hbox);
    dialog->show();
}
