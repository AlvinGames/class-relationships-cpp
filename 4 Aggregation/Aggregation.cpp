//Class_Relationships
//
//Aggregation.cpp
//

#include<iostream>
#include<string>
#include<vector>

/*
 * ============================================
 * 2.3 АГРЕГАЦИЯ
 *
 * Ассоциация показывает отношения между
 * объектами-экземплярами класса.
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

class IdCard
{
public:
	IdCard(int number)
	{
		this->number = number;
	}

	//Accessors
	inline void setNumber	(int number)				{ this->number	= number;	}
	inline void setDate		(const std::string& date)	{ this->date	= date;		}

	inline const int&			getNumber() const { return this->number;	}
	inline const std::string&	getDate()	const { return this->date;		}

private:
	std::string date;
	int			number;

};

class Room
{
public:
	Room(int number)
	{
		this->number = number;
	}

	//Accessors
	inline void setNumber(int number) { this->number = number; }

	inline const int& getNumber() const { return this->number; }

private:
	int number;
};

class Department;

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

	void addRoom(Room* room)
	{
		this->room.push_back(room);
	}
	void removeRoom(std::size_t number)
	{
		this->room.erase(this->room.begin() + number);
	}

	//Accessors
	inline void setPosition		(const std::string& position)	{ this->position	= position;		}
	inline void setIdCard		(IdCard* iCard)					{ this->iCard		= iCard;		}
	inline void setDepartment	(Department* department)		{ this->department	= department;	}

	inline const std::string&			getPosition()		const { return this->position;		}
	inline const IdCard&				getIdCard()			const { return *this->iCard;		}
	inline const Department&			getDepartment()		const { return *this->department;	}
	inline const std::vector<Room*>&	getRoom()			const { return this->room;			}

private:
	std::vector<Room*>	room;
	std::string			position;
	IdCard*				iCard		= nullptr;
	Department*			department = nullptr;
};

class Department
{
public:
	Department(const std::string& name)
	{
		this->name = name;
	}

	void addEmployee(Employee* emplloyee)
	{
		this->employees.push_back(emplloyee);
		emplloyee->setDepartment(this);
	}
	void removeEmployee(std::size_t number)
	{
		this->employees.erase(this->employees.begin() + number);
	}

	//Accessors
	inline void setName(const std::string& name) { this->name = name; }

	inline const std::string&			getName()		const { return this->name;		}
	inline const std::vector<Employee*> getEmployees()	const { return this->employees; }

private:
	std::vector<Employee*>	employees;
	std::string				name;
	
};

int main()
{
	setlocale(LC_ALL, "RU");

	IdCard* card = new IdCard(123);
	card->setDate("2015-12-31");

	Employee* enginer = new Employee("John", "Connor", "Manager");
	enginer->setIdCard(card);

	Room* room101 = new Room(101);
	Room* room321 = new Room(321);

	enginer->addRoom(room101);
	enginer->addRoom(room321);

	Department* programmersDepartment = new Department("Programmers");
	programmersDepartment->addEmployee(enginer);

	//========================================================================================//

	std::cout << enginer->getName() + " " + enginer->getSurname()
		<< " работает на должности " + enginer->getPosition() << std::endl;

	std::cout << "Удостоверение действует до " + enginer->getIdCard().getDate() << std::endl;

	std::cout << "Может находиться в помещениях: ";
	for (const auto room : enginer->getRoom())
	{
		std::cout << room->getNumber() << " ";
	}
	std::cout << std::endl;

	std::cout << "Относится к отделу " + enginer->getDepartment().getName() << std::endl;

	//========================================================================================//

	delete programmersDepartment;
	delete room321;
	delete room101;
	delete enginer;
	delete card;
	

	return 0;
}
