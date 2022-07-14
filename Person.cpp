#include "Person.h"

//class Person

Person::Person(std::string tmp_fullname, int tmp_height, int tmp_weight, std::string tmp_gender,
    std::string tmp_country, std::string tmp_email) :
    fullname(tmp_fullname),
    height(tmp_height),
    weight(tmp_weight),
    gender(tmp_gender),
    country(tmp_country),
    email(tmp_email)
{
    checkInput();
}

bool Person::isHeight()
{
    if (height >= 200)
        return true;
}

bool Person::isInUkraine()
{
    if (country == "Ukraine")
        return true;
}

std::string Person::Info()
{
    return "Person:\n" + fullname + "\nHeight" + std::to_string(height)
        + "\nWeight: " + std::to_string(weight)
        + "\nGender: " + gender
        + "\nCountry" + country
        + "\nEmail:" + email
        + "\nLives in Ukraine: " + std::string(isInUkraine() ? "Yes" : "No")
        + "\nTaller than 200 cm" + std::string(isHeight() ? "Yes" : "No");
}

void Person::checkInput()
{
    if (height <= 0 && weight <= 0)
        throw std::invalid_argument("Wrong height and weight");

    if (height <= 0)
        throw std::invalid_argument("Wrong height");

    if (weight <= 0)
        throw std::invalid_argument("Wrong weight");

    if (gender != "Male" || gender != "Female")
        throw std::invalid_argument("There are only two genders");
}

// Workmen

Workmen::Workmen(std::string tmp_fullname, int tmp_height, int tmp_weight,
    std::string tmp_gender, std::string tmp_country, std::string tmp_email,
    std::string tmp_factory, std::string tmp_work, int tmp_payment)
    :
    Person(tmp_fullname, tmp_height, tmp_weight, tmp_gender, tmp_country, tmp_email),
    factory(tmp_factory),
    work(tmp_work),
    payment(tmp_payment)
{
    Workmen::checkInput();
}

bool Workmen::isHeight()
{
    if (getHeight() >= 200)
        return true;
}

bool Workmen::isInUkraine()
{
    if (getCountry() == "Ukraine")
        return true;
}

std::string Workmen::Info()
{
    return "Person:\n" + getFullName() + "\nHeight" + std::to_string(getHeight())
        + "\nWeight: " + std::to_string(getWeight())
        + "\nGender: " + getGender()
        + "\nCountry" + getCountry()
        + "\nEmail:" + getEmail()
        + "\nLives in Ukraine: " + std::string(isInUkraine() ? "Yes" : "No")
        + "\nTaller than 200 cm" + std::string(isHeight() ? "Yes" : "No")
        + "\nFactory where person works: " + factory
        + "\nWork: " + work
        + "\nPayment per month: " + std::to_string(payment);
}

void Workmen::checkInput()
{
    Person::checkInput();

    if (payment <= 0)
        throw std::invalid_argument("Payment can't be less than 0.");
}

// Electician

Electrician::Electrician(std::string tmp_fullname, int tmp_height, int tmp_weight, std::string tmp_gender,
    std::string tmp_country, std::string tmp_email,
    int tmp_experience, int tmp_rank, Object* tmp_object)
    :
    Person(tmp_fullname, tmp_height, tmp_weight, tmp_gender, tmp_country, tmp_email),
    experience(tmp_experience),
    rank(tmp_rank),
    object(tmp_object)
{
    Electrician::checkInput();
}

bool Electrician::isHeight()
{
    if (getHeight() >= 200)
        return true;
}

bool Electrician::isInUkraine()
{
    if (getCountry() == "Ukraine")
        return true;
}

//bool Electrician::isCanWork()
//{
//  return
//}


std::string Electrician::Info()
{
    return "Person:\n" + getFullName() + "\nHeight" + std::to_string(getHeight())
        + "\nWeight: " + std::to_string(getWeight())
        + "\nGender: " + getGender()
        + "\nCountry" + getCountry()
        + "\nEmail:" + getEmail()
        + "\nLives in Ukraine: " + std::string(isInUkraine() ? "Yes" : "No")
        + "\nTaller than 200 cm" + std::string(isHeight() ? "Yes" : "No")
        + "\nExperience: " + std::to_string(experience)
        + "\nRank: " + std::to_string(rank)
        + "\nObject: " + object->getName();
}


void Electrician::checkInput()
{
    Person::checkInput();

    //    if (payment <= 0)
    //        throw std::invalid_argument("Payment can't be less than 0.");
}