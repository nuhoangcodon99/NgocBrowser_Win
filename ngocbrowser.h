#ifndef NgocBROWSER_H
#define NgocBROWSER_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class NgocBrowser; }
QT_END_NAMESPACE

class NgocBrowser : public QMainWindow
{
    Q_OBJECT

public:
    NgocBrowser(QWidget *parent = nullptr);
    ~NgocBrowser();

private slots:
    void on_addressEdit_returnPressed();

    void on_backButton_pressed();

    void on_forwardButton_pressed();

    void on_helpButton_pressed();

    void on_webView_urlChanged(const QUrl &url);

private:
    Ui::NgocBrowser *ui;

    // Add webEngineView programatically
    QWebEngineView *webView;
};
#endif // NgocBROWSER_H
