#include <iostream>
#include <QString>

// ��Ʒ�ӿ�
class IWidget {
public:
    virtual QString style() = 0;
};

// �����Ʒ��Button
class Button : public IWidget {
public:
    QString style() {
        return "Button Style";
    }
};

// �����Ʒ��TextBox
class TextBox : public IWidget {
public:
    QString style() {
        return "TextBox Style";
    }
};

// �����ӿ�
class WidgetFactory {
public:
    virtual IWidget* createWidget() = 0;
};

// Button����
class ButtonFactory : public WidgetFactory {
public:
    IWidget* createWidget() {
        return new Button();
    }
};

// TextBox����
class TextBoxFactory : public WidgetFactory {
public:
    IWidget* createWidget() {
        return new TextBox();
    }
};

int main() {
    // ʹ��Button����
    WidgetFactory* factory = new ButtonFactory();
    IWidget* widget = factory->createWidget();
    std::cout << "Widget style: " << widget->style().toStdString() << std::endl;

    // ������Դ
    delete widget;
    delete factory;

    // ʹ��TextBox����
    factory = new TextBoxFactory();
    widget = factory->createWidget();
    std::cout << "Widget style: " << widget->style().toStdString() << std::endl;

    // ������Դ
    delete widget;
    delete factory;


    return 0;
}