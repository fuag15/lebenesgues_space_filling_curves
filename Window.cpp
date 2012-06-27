#include "Window.h"
#include "Viewer.h"

Window::Window():QWidget()
{
    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setRange(0, 11);
    
    Viewer *viewer = new Viewer();
    
    connect(slider, SIGNAL(valueChanged(int)), viewer, SLOT(setRec(int)));
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(viewer);
    layout->addWidget(slider);
    setLayout(layout);
    
    slider->setValue(5);
}