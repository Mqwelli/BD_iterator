#include "list.h"
template <class T> Iterator<T>::Iterator() {
	current = new Day<T>();
}

template <class T> Iterator<T>::Iterator(Day<T>* first) : current(first) {}

template <class T>
Iterator<T>::~Iterator() {
	current = nullptr;
}
template <class T>
Iterator<T>::Iterator(Iterator& other) {
	current = other.current;
}
template <class T>
Day<T>* Iterator<T>::getValue() {
	return current;
}
template <class T> Day<T>& Iterator<T>::operator* () { return *current; }
template <typename T> Iterator<T>& Iterator<T>::operator++ ()
{
	if (current != nullptr && current->next != nullptr) {
		int count = 1;
		Day<T>* targetfwd = current;
		Day<T>* targetrwd = current;
		while (targetfwd->next != nullptr) {
			targetfwd = targetfwd->next;
			count++;
		}
		while (targetrwd->prev != nullptr) {
			targetrwd = targetrwd->prev;
			count++;
		}
		current = current->next;
		current->data += count;
	}
	return *this;
}
template <typename T> Iterator<T>& Iterator<T>::operator++ (int) {
	if (current->next != nullptr)
	{
		current = current->next;
	}
	return *this;
}
template <typename T> Iterator<T>& Iterator<T>::operator--() {
	if (current != nullptr && current->prev != nullptr)
	{
		current = current->prev;
	}
	return *this;
}
template <typename T> Iterator<T>& Iterator<T>::operator--(int) {
	if (current != nullptr && current->next != nullptr) {
		int count = 1;
		Day<T>* targetfwd = current;
		Day<T>* targetrwd = current;
		while (targetfwd->next != nullptr) {
			targetfwd = targetfwd->next;
			count++;
		}
		while (targetrwd->prev != nullptr) {
			targetrwd = targetrwd->prev;
			count++;
		}
		current = current->prev;
		current->data += count;
	}
	return *this;
}

template <class T> Iterator<T>& Iterator<T>::operator =(const Iterator<T>&& other)
{
	if (this == &other)
		return *this;

	current = other.current;
	return *this;
}
template <class T> Iterator<T>& Iterator<T>::operator =(const Iterator<T>& other)
{
	if (this == &other)
		return *this;

	current = other.current;
	return *this;
}

template <typename T> Schedule<T>::Schedule() : trainingTime(nullptr) {}

template <typename T> Schedule<T>::Schedule(Schedule&& oldList) : Schedule(oldList.Schedule) {
	oldList.trainingTime = nullptr;
}

template <typename T> void Schedule<T>::clear() {
	while (trainingTime != nullptr) {
		Day<T>* temp = trainingTime;
		trainingTime = trainingTime->next;
		delete temp;
	}
}

template <typename T> Schedule<T>::~Schedule() {
	clear();
}

template <typename T> Schedule<T>& Schedule<T>::operator=(const Schedule& other) {
	if (this == &other) return *this;
	clear();
	Day<T>* curnode = other.trainingTime;
	while (curnode != nullptr) {
		pushBack(curnode->data);
		curnode = curnode->next;
	}
	return *this;
}

template <typename T> Schedule<T>& Schedule<T>::operator=(Schedule&& other) {
	if (this == &other) return *this;
	clear();
	trainingTime = other.trainingTime;
	other.trainingTime = nullptr;
	return *this;
}

template <typename T> Iterator<T> Schedule<T>::begin() {
	iterator = Iterator<T>(trainingTime);
	return iterator;
}

template <typename T> Iterator<T> Schedule<T>::end() {
	Day<T>* temp = trainingTime;
	while (temp != nullptr && temp->next != nullptr) {
		temp = temp->next;
	}
	iterator = Iterator<T>(temp);
	return iterator;
}

template <typename T> bool Schedule<T>::empty() {
	return Schedule == nullptr;
}

template <class T> size_t Schedule<T>::size() {
	size_t count = 0;
	Day<T>* current = trainingTime;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}
template <class T> size_t Schedule<T>::getMaxSize() {
	return maxSize;
}

template <class T> void Schedule<T>::pushBack(T value) {
	if (size() != maxSize) {
		Day<T>* newElem = new Day<T>(value);
		newElem->next = nullptr;
		if (trainingTime == nullptr) {
			newElem->prev = nullptr;
			trainingTime = newElem;
		}
		else {
			Day<T>* temp = trainingTime;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newElem;
			newElem->prev = temp;
		}
	}
}

template <class T> void Schedule<T>::popBack() {
	if (trainingTime != nullptr) {
		Day<T>* temp = trainingTime;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		if (temp->prev != nullptr) {
			temp->prev->next = nullptr;
		}
		else {
			trainingTime = nullptr;
		}
		delete temp;
	}
}

template <class T> void Schedule<T>::pushFront(T value) {
	if (size() != maxSize) {
		Day<T>* newElem = new Day<T>(value);
		newElem->next = trainingTime;
		newElem->prev = nullptr;
		if (trainingTime != nullptr) {
			trainingTime->prev = newElem;
		}
		trainingTime = newElem;
	}
}

template <class T> void Schedule<T>::popFront() {
	if (trainingTime != nullptr) {
		Day<T>* temp = trainingTime;
		trainingTime = trainingTime->next;
		if (trainingTime != nullptr) {
			trainingTime->prev = nullptr;
		}
		delete temp;
	}
};