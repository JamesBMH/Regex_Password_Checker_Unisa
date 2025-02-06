//13413120 JBM HERTZOG Question 3
#include "gui.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>
#include <QValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QErrorMessage>

Gui::Gui(QWidget *parent)
    : QWidget(parent),
    instructions(new QLabel("Choose one of the options and press the button to validate your passsword")),
    passwordEdit{new QLineEdit},
    rule1{new QCheckBox("Min 5 characters, no spaces allowed")},
    rule2{new QCheckBox("Exactly 5 characters. 3rd character is a digit, or alphabet character")},
    rule3{new QCheckBox("Min 4 digits. Max 6 digits. Starting digit not zero")},
    validateButton{new QPushButton("Validate")},
    ruleGroup{new QButtonGroup}
{
    setup();

    ruleGroup->addButton(rule1);
    ruleGroup->addButton(rule2);
    ruleGroup->addButton(rule3);
    // ruleGroup->setExclusive(true);

    disableWidgets();

    connect(ruleGroup, &QButtonGroup::buttonClicked, this, &Gui::checkClicked);
    connect(passwordEdit, &QLineEdit::textChanged, this, &Gui::checkEdit);
    connect(validateButton, &QPushButton::clicked, this, &Gui::passwordValidation);
}

Gui::~Gui() {}

void Gui::setup()
{
    QVBoxLayout *layout{new QVBoxLayout};
    layout->addWidget(instructions);
    layout->addWidget(rule1);
    layout->addWidget(rule2);
    layout->addWidget(rule3);
    layout->addWidget(passwordEdit);
    layout->addWidget(validateButton);

    this->setLayout(layout);
}

void Gui::disableWidgets()
{
    passwordEdit->setDisabled(true);
    validateButton->setDisabled(true);
}

void Gui::checkClicked()
{
    if (rule1->isChecked() | rule2->isChecked() | rule3->isChecked()){
        passwordEdit->setDisabled(false);
        passwordEdit->clear();
    } else{
        passwordEdit->setDisabled(true);
    }

    if (rule1->isChecked()){
        setRule1Validator();
        passwordEdit->setFocus();
    } else if (rule2->isChecked()){
        setRule2Validator();
        passwordEdit->setFocus();
    } else if (rule3->isChecked()){
        setRule3Validator();
        passwordEdit->setFocus();
    }
}

void Gui::checkEdit()
{
    if (passwordEdit->text() == ""){
        validateButton->setDisabled(true);
    } else{
        validateButton->setDisabled(false);
    }
}

void Gui::setRule1Validator()
{
    //All characters present on my keyboard, no white spaces
    QRegularExpression re1("[a-zA-z0-9!@#$%^&*()-=+*/?>\'\"{}`~|]+");
    QValidator *passwordValidator{new QRegularExpressionValidator(re1)};

    passwordEdit->setValidator(passwordValidator);
}

void Gui::setRule2Validator()
{
    QRegularExpression re2("[a-zA-z0-9!@#$%^&*()-=+*/?>\'\"{}`~|\\s]{2}[a-zA-Z0-9]{1}[a-zA-z0-9!@#$%^&*()-=+*/?>\'\"{}`~|\\s]{2}");
    QValidator *passwordValidator{new QRegularExpressionValidator(re2)};

    passwordEdit->setValidator(passwordValidator);
}

void Gui::setRule3Validator()
{
    QRegularExpression re3("[1-9]{1}[0-9]{5}");
    QValidator *passwordValidator{new QRegularExpressionValidator(re3)};

    passwordEdit->setValidator(passwordValidator);
}

void Gui::passwordValidation()
{
    if (rule1->isChecked()){
        if (passwordEdit->text().length() < 5){
            QErrorMessage *error{new QErrorMessage};
            error->setWindowTitle("Invalid input");
            error->showMessage("Password is too short");
            passwordEdit->clear();
            passwordEdit->setFocus();
            validateButton->setDisabled(true);
        } else{
            QMessageBox *passed{new QMessageBox};
            passed->setText("Your password is valid");
            passed->exec();
        }
    } else if (rule2->isChecked()){
        if (passwordEdit->text().length() == 5){
            QMessageBox *passed{new QMessageBox};
            passed->setText("Your password is valid");
            passed->exec();
        } else{
            QErrorMessage *error{new QErrorMessage};
            error->setWindowTitle("Invalid input");
            error->showMessage("Password is too short");
            passwordEdit->clear();
            passwordEdit->setFocus();
            validateButton->setDisabled(true);
        }
    } else if (rule3->isChecked()){
        if (passwordEdit->text().length() < 4){
            QErrorMessage *error{new QErrorMessage};
            error->setWindowTitle("Invalid input");
            error->showMessage("Password is too short");
            passwordEdit->clear();
            passwordEdit->setFocus();
            validateButton->setDisabled(true);
        } else{
            QMessageBox *passed{new QMessageBox};
            passed->setText("Your password is valid");
            passed->exec();
        }
    }
}
