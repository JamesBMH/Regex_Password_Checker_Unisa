//13413120 JBM HERTZOG Question 3
#ifndef GUI_H
#define GUI_H

#include <QWidget>

class QLineEdit;
class QCheckBox;
class QPushButton;
class QLabel;
class QButtonGroup;

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();

private slots:
    void setup();
    void disableWidgets();
    void checkClicked();
    void checkEdit();
    void setRule1Validator();
    void setRule2Validator();
    void setRule3Validator();
    void passwordValidation();

private:
    QLineEdit *passwordEdit;
    QLabel *instructions;
    QCheckBox *rule1;
    QCheckBox *rule2;
    QCheckBox *rule3;
    QButtonGroup *ruleGroup;
    QPushButton *validateButton;
};
#endif // GUI_H
