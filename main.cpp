#include <QApplication>
#include "Window.h"
#include "Viewer.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Window window;
    window.setWindowTitle("Lebesgue space-filling curves");
    window.show();

    return app.exec();
}