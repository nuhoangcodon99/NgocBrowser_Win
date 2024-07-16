#include "ngocbrowser.h"
#include "ui_ngocbrowser.h"
#include <QMessageBox>
#include <QTimer>

NgocBrowser::NgocBrowser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NgocBrowser)
{
    ui->setupUi(this);

    // Add webEngineView manually
    webView = new QWebEngineView(ui->view);
    int webViewWidth = ui->view->geometry().width();
    int webViewHeight = ui->view->geometry().height();
    webView->setGeometry(0,0, webViewWidth, webViewHeight);
    webView->load(QUrl("http://google.com"));

    /**
     * @brief Connect Signal & Slot manually
     */
    // If URL of webEngineView changes, the address text changes also
    connect(webView, SIGNAL(urlChanged(const QUrl&)),
            this, SLOT(on_webView_urlChanged(const QUrl&)));

    // If webEngineView crash when loading page, reload it.
    connect(webView, &QWebEngineView::renderProcessTerminated,
                [this](QWebEnginePage::RenderProcessTerminationStatus termStatus, int statusCode) {
               QTimer::singleShot(0, [this] { webView->reload(); });
        });
}

NgocBrowser::~NgocBrowser()
{
    delete ui;
}


void NgocBrowser::on_addressEdit_returnPressed()
{
    webView->load(ui->addressEdit->text());
}


void NgocBrowser::on_backButton_pressed()
{
    webView->back();
}


void NgocBrowser::on_forwardButton_pressed()
{
    webView->forward();
}


void NgocBrowser::on_helpButton_pressed()
{
    QMessageBox* helpBox = new QMessageBox;
    QString message = "Xin chao\n";
    message += "Day la trinh duyet cua NgocCoder \n";
    message += "de xem JAV\n";
    helpBox->setText(message);
    helpBox->exec();
}

void NgocBrowser::on_webView_urlChanged(const QUrl &url)
{
    ui->addressEdit->setText(webView->url().toString());
}

