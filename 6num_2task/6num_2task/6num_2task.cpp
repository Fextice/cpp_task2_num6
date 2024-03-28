#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component { // класс граф.компонента
protected:
    string name;
    bool visible;
public:
    Component(const string& name) : name(name), visible(true) {}
    virtual void draw() = 0;
    virtual void setVisible(bool isVisible) {
        visible = isVisible;
    }
};

class Window : public Component { // класс "окно"
private:
    vector<Component*> components;
public:
    Window(const string& name) : Component(name) {}
    void addComponent(Component* component) {
        components.push_back(component);
    }
    void draw() override {
        if (visible) {
            cout << "Drawing Window: " << name << endl;
            for (Component* component : components) {
                component->draw();
            }
        }
    }
    ~Window() {
        for (Component* component : components) {
            delete component;
        }
    }
};

class Label : public Component { // класс "надпись"
public:
    Label(const string& name) : Component(name) {}
    void draw() override {
        if (visible) {
            cout << "Drawing Label: " << name << endl;
        }
    }
};

class Button : public Component { // класс "кнопка"
public:
    Button(const string& name) : Component(name) {}
    void draw() override {
        if (visible) {
            cout << "Drawing Button: " << name << endl;
        }
    }
};

int main() {
    Window* mainWindow = new Window("Main Window");

    Label* label = new Label("Username:");
    Button* button = new Button("Submit");

    mainWindow->addComponent(label);
    mainWindow->addComponent(button);

    mainWindow->draw();

    delete mainWindow;

    return 0;
}
