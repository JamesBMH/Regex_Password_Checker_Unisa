//13413120 JBM HERTZOG Question 3
#ifndef GUI_H
#define GUI_H

#include <QWidget>

//Forward declarations
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
    //Sets up the layout of the GUI
    void setup();
    //Disables textedit and validate button
    void disableWidgets();
    //If a checkbox is not clicked the text edit is disabled
    //If a new checkbox is clicked the text edit is cleared
    //Sets validator to use depending on selected checkbox
    void checkClicked();
    //Disables validate button if text edit is empty
    void checkEdit();
    //Sets validator for text edit
    void setRule1Validator();
    void setRule2Validator();
    void setRule3Validator();
    //Displays appropriate message after password validation
    //Clears the text edit if password is wrong and sets focus back on text edit
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
