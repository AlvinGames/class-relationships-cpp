//Class_Relationships
//
//Generalization.cpp
//

#include<iostream>
#include<string>

/*
 * ============================================
 * 1 ОБОБЩЕНИЕ
 * 
 * Отношение обобщения - это наследование.
 *
 * ... ... ... ... ...
 *
 * ============================================
 */

class Man
{
public:
	//Accessors
	inline void setName		(const std::string& name)		{ this->name	= name;		}
	inline void setSurname	(const std::string& surname)	{ this->surname = surname;	}

	inline const std::string& getName()		const { return this->name;		}
	inline const std::string& getSurname()	const { return this->surname;	}

protected:
	std::string name;
	std::string surname;
};

class Employee : public Man
{
public:
	Employee(
		const std::string& name,
		const std::string& surname,
		const std::string& position
	)
	{
		this->name		= name;
		this->surname	= surname;
		this->position	= position;
	}

private:
	std::string position;

};

int main()
{
	Man* enginer = new Employee("John", "Connor", "Manager");

	std::cout << enginer->getName()		<< std::endl;
	std::cout << enginer->getSurname()	<< std::endl;

	delete enginer;

	//  Класс "Man"(человек) - более абстрактный, а "Employee"(сотрудник) более специализированный.
	//  Класс "Employee" наследует свойства и методы "Man".

	return 0;
}
