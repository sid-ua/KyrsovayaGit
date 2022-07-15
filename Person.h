#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <stdexept>
#include <string>


class Person {
public:
    virtual ~Person();

    Person();
    Person(std::string tmp_fullname, int tmp_height, int tmp_weight, std::string tmp_gender, std::string tmp_country, std::string tmp_email);

    virtual bool isHeight();
    virtual bool isInUkraine();

    virtual std::string getFullName() { return fullname; }
    virtual int getHeight() { return height; }
    virtual int getWeight() { return weight; }
    virtual std::string getGender() { return gender; }
    virtual std::string getCountry() { return country; }
    virtual std::string getEmail() { return email; }

    void setFullName(std::string m_fullname) { fullname = m_fullname; }
    void setHeight(int m_height) { height = m_height; }
    void setWeight(int m_weight) { weight = m_weight; }
    void setGender(std::string m_gender) { gender = m_gender; }
    void setCountry(std::string m_country) { country = m_country; }
    void setEmail(std::string m_email) { email = m_email; }

    virtual std::string Info();
    virtual void checkInput();

private:
    std::string fullname;
    int height;
    int weight;
    std::string gender;
    std::string country;
    std::string email;
};

class Workmen : public Person
{
public:
    Workmen(std::string tmp_fullname, int tmp_height, int tmp_weight, std::string tmp_gender,
        std::string tmp_country, std::string tmp_email, std::string tmp_factory, std::string tmp_work, int tmp_payment);

    bool isHeight() override;
    bool isInUkraine() override;

    std::string getFactory() { return factory; }
    std::string getWork() { return work; }
    int getPayment() { return payment; }

    void setFactory(std::string m_factory) { factory = m_factory; }
    void setWork(std::string m_work) { work = m_work; }
    void setPayment(int m_payment) { payment = m_payment; }

    std::string Info() override;
    void checkInput() override;

private:
    std::string factory;
    std::string work;
    int payment;
};


class Object
{
public:
    Object(std::string tmp_name, int tmp_min_exp, int tmp_min_rank);

    std::string getName() { return name; }
    int getMinExp() { return min_exp; }
    int getMinRank() { return min_rank; }

    void setName(std::string m_name) { name = m_name; }
    void setMinExp(int m_min_exp) { min_exp = m_min_exp; }
    void setMinRank(int m_min_rank) { min_rank = m_min_rank; }

    void checkInput();

private:
    std::string name;
    int min_exp;
    int min_rank;
};

class Electrician : public Person
{
public:
    Electrician(std::string tmp_fullname, int tmp_height, int tmp_weight, std::string tmp_gender,
        std::string tmp_country, std::string tmp_email, int tmp_experience, int tmp_rank, Object* tmp_object);

    bool isHeight() override;
    bool isInUkraine() override;
    bool isCanWork();

    int getExperience() { return experience; }
    int getRank() { return rank; }
    Object* getObject() { return object; }

    void setExperience(int m_experience) { experience = m_experience; }
    void setRank(int m_rank) { rank = m_rank; }
    void setObject(Object* m_object) { object = m_object; }

    std::string Info() override;
    void checkInput() override;

private:
    int experience;
    int rank;
    Object* object;
};
#endif