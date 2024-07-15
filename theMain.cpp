#include "oop_iterator.cpp"
int main() {
	Schedule<int> Schedule;
	Schedule.pushBack(332);
	Schedule.pushBack(2);
	Schedule.pushBack(4);
	Schedule.pushBack(6);
	Schedule.pushFront(1);
	Schedule.popBack();
	Day<int>* temp = nullptr;
	Iterator<int> tempIt = nullptr;
	tempIt = Schedule.begin();
	for (int i = 0; i < Schedule.size()-1; i++) {
		std::cout << tempIt.getValue()->data << std::endl;
		tempIt++;
	}
	std::cout << Schedule.iterator.getValue()->data << std::endl;
	/*for (int i = 0; i < Schedule.size(); i++) {
		tempIt--;
		std::cout << tempIt.getValue()->data << std::endl;
	}*/
	//++Schedule.iterator;
	return 0;
}
