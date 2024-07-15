#include <iostream>
template <class T> struct Day
{
public:
	T data;
	Day* prev = nullptr;
	Day* next = nullptr;
	Day(T value) : data(value) {};
	Day() {};
};
template <class T> class Iterator
{
private:
	Day<T>* current = nullptr;
public:
	Iterator();
	~Iterator();
	Iterator(Day<T>* first);
	Iterator(Iterator<T>& other);
	Day<T>* getValue();
	Day<T>& operator*();
	Iterator<T>& operator++(int);
	Iterator<T>& operator--(int);
	Iterator<T>& operator++();
	Iterator<T>& operator--();
	Iterator<T>& operator =(const Iterator<T>& other);
	Iterator<T>& operator =(const Iterator<T>&& other);
};
template <class T> class Schedule
{
private:
	Day<T>* trainingTime;
	size_t maxSize = 20;
public:
	Schedule();
	Schedule(Schedule&& a);
	~Schedule();
	Schedule& operator =(const Schedule& other);
	Schedule& operator =(Schedule&& other);
	Iterator<T> iterator;
	Iterator<T> begin();
	Iterator<T> end();
	bool empty();
	size_t size();
	size_t getMaxSize();
	void clear();
	void pushBack(T value);
	void popBack();
	void pushFront(T value);
	void popFront();
};
