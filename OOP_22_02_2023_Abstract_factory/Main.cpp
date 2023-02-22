#include<iostream>
#include<string>
#include<memory>
#include<tuple>

class Button {
public:
	virtual void paint() = 0;
	virtual ~Button(){}
};

class WinButton : public Button {
public:
	void paint() override {
		std::cout << "Paint Win";
	}
};
class MacButton : public Button {
public:
	void paint() override {
		std::cout << "Paint Mac";
	}
};
class CheckBox {
public:
	virtual void paint() = 0;
	virtual ~CheckBox() {}

};

class MacCheckBox : public CheckBox {
public:
	void paint() override {
		std::cout << "Paint MacCheckBox";
	}
};

class WinCheckBox : public CheckBox {
public:
	void paint() override {
		std::cout << "Paint WinCheckBox";
	}
};

class GUIFactory {
public:
	virtual std::shared_ptr <Button> createButton() = 0;
	virtual std::shared_ptr <CheckBox> createCheckBox() = 0;
	virtual ~GUIFactory() {}
};

class WinFactory : public GUIFactory {
public:
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<WinButton>();
	}
};

class MakFactory : public GUIFactory {
public:
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<MacButton>();
	}
};

class Application {
public:
	Application(std::shared_ptr<GUIFactory> factory) {
		_factory = factory;
	}
	void createUI() {
		_button = _factory->createButton();
		_checkBox = _factory->createCheckBox();
	}
	void paint() {
		_button->paint();
		_checkBox->paint();
	}

private:
	std::shared_ptr<GUIFactory> _factory;
	std::shared_ptr<Button> _button;
	std::shared_ptr<CheckBox> _checkBox;
};



int main() {


	std::tuple<int, float, std::string> t(5, 4.2f, "hello");
	std::cout << std::get<2>(t);


	return 0;
}
