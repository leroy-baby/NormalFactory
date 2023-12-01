#include <iostream>
#include <QString>

// 产品接口
class IWidget {
public:
    virtual QString style() = 0;
};

// 具体产品：Button
class Button : public IWidget {
public:
    QString style() {
        return "Button Style";
    }
};

// 具体产品：TextBox
class TextBox : public IWidget {
public:
    QString style() {
        return "TextBox Style";
    }
};

// 工厂接口
class WidgetFactory {
public:
    virtual IWidget* createWidget() = 0;
};

// Button工厂
class ButtonFactory : public WidgetFactory {
public:
    IWidget* createWidget() {
        return new Button();
    }
};

// TextBox工厂
class TextBoxFactory : public WidgetFactory {
public:
    IWidget* createWidget() {
        return new TextBox();
    }
};

int main() {
    // 使用Button工厂
    WidgetFactory* factory = new ButtonFactory();
    IWidget* widget = factory->createWidget();
    std::cout << "Widget style: " << widget->style().toStdString() << std::endl;

    // 清理资源
    delete widget;
    delete factory;

    // 使用TextBox工厂
    factory = new TextBoxFactory();
    widget = factory->createWidget();
    std::cout << "Widget style: " << widget->style().toStdString() << std::endl;

    // 清理资源
    delete widget;
    delete factory;


    return 0;
}