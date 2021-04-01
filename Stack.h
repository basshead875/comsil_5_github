#include "LinkedList.h"

template <class T> //class 및 function 앞 template 선언

class Stack : public LinkedList<T>{ //LinkedList 클래스를 상속받음
	public:
		bool Delete(T &element){ //LinkedList의 delete 함수와 다르게 첫 번째 원소를 삭제
			if(this->first == NULL) { //원소가 존재하지 않을 경우, delete 함수를 수행할 수 없으므로 false 리턴
				return false;
			}
			Node<T>* current  = this->first; //current라는 iterator를 생성하고 첫 번째 원소에 할당, first는 상위 클래스 LinkedList에서 선언된 protected 변수이므로 this를 통해 접근		
			element = current->data; //연결을 끊기 전, 삭제한 원소를 리턴해야 할 경우가 있으므로 current를 삭제하기 전, element 변수에 할당
			this->first = current->link; //두 번째 원소가 새로운 첫 번째 원소가 되므로 첫 번째 원소의 link 값인 두 번째 원소의 주소값을 해당 인스턴스의 first로 갱신
			delete current; //current를 다 사용하였으므로 삭제
			this->current_size--; //manual로 1 감소             		
			return true;
			}
};
