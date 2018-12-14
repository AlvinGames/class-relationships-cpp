//Class_Relationships
//
//Binary_Association.cpp
//

#include<iostream>
#include<string>

/*
 * ============================================
 * 2.1 АССОЦИАЦИЯ (БИНАРНАЯ)
 *
 * Ассоциация показывает отношения между
 * объектами-экземплярами класса.
 *
 * Каждому объекту может соответствовать
 * только один экземпляр.
 * 
 * Мощность связи 1 к 1.
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
	inline void setNumber(int number)				{ this->number	= number;	}
	inline void setDate(const std::string& date)	{ this->date	= date;		}

	inline const int&			getNumber() const { return this->number;	}
	inline const std::string&	getDate()	const { return this->date;		}

private:
	std::string date;
	int			number;

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

	//Accessors
	inline void setPosition	(const std::string& position)	{ this->position	= position;	}
	inline void setIdCard	(IdCard* iCard)					{ this->iCard		= iCard;	}

	inline const std::string&	getPosition()	const { return this->position;	}
	inline const IdCard&		getIdCard()		const { return *this->iCard;	}

private:
	std::string position;
	IdCard*		iCard = nullptr;
};

int main()
{
	setlocale(LC_ALL, "RU");

	IdCard* card = new IdCard(123);
	card->setDate("2015-12-31");

	Employee* enginer = new Employee("John", "Connor", "Manager");
	enginer->setIdCard(card);

	//========================================================================================//

	std::cout << enginer->getName() + " " + enginer->getSurname()
		<< " работает на должности " + enginer->getPosition() << std::endl;

	std::cout << "Удостоверение действует до " + enginer->getIdCard().getDate() << std::endl;

	//========================================================================================//

	delete enginer;
	delete card;

	// Класс Employee и IdCard связаны
	// Из экземпляра объекта Employee мы можем узнать о связанном с ним объектом типа IdCard,
	// значит навигация(стрелочка на линии) направлена от Employee к IdCard.
	// Employee --> IdCard

	return 0;
}
