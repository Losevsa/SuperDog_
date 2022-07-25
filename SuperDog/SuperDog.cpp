#include <iostream>
#include <vector>

class Talent
{
public:
	virtual void setTalent(std::string talent) = 0;
	virtual void showTalent() = 0;


protected:
	std::vector<std::string> talent;
};

class Animal
{
public:
	virtual void voice() = 0;

	void setAnimalName(std::string name)
	{
		this->name = name;
	}

	std::string  getAnimalName()
	{
		return name;
	}

private:
	std::string name;
};

class Dog : virtual public Animal, virtual public Talent
{
public:

	Dog(std::string name)
	{
		setAnimalName(name);
	}

	virtual void setTalent(std::string talent)
	{
		this->talent.push_back(talent);
	}

	virtual void showTalent()
	{
		std::cout << "Dog has talants: " << std::endl;
		for (int i = 0; i < talent.size(); i++)
		{
			std::cout << talent[i] << std::endl;
		}
	}

	virtual void voice()
	{
		std::cout << "Dog: wof" << std::endl;
	}

	void setName()
	{
		setAnimalName("qwe");
	}

	std::string getName()
	{
		return getAnimalName();
	}

};


int main()
{
	std::string name;
	std::cout << "Enter dog name: ";
	std::cin >> name;
	std::cout << "Enter count of talants: ";
	int talants;
	std::cin >> talants;


	Dog* dog = new Dog(name);

	std::cout << "Let's enter talants " << std::endl;

	for (int i = 0; i < talants; i++)
	{
		std::string tal;
		std::cout << "Talant # " << i + 1 << ": ";
		std::cin >> tal;
		dog->setTalent(tal);
	}

	std::cout << "You: " << dog->getName() << "!" << std::endl;
	dog->voice();

	std::cout << "You: " << dog->getName() << " show your talants" << std::endl;

	dog->showTalent();

	return 0;
}
