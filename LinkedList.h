#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

template <class T> //class 및 function 앞 template 선언

class Node{
	public:
		T data; //Node가 가지고 있는 값, template을 사용해 기존 int형에서 다양한 자료형을 사용 가능
		Node<T> *link; //LinkedList에 Node가 할당될 경우 다음 순서의 Node를 가리키는 주소값
		Node(T element){ //Node 생성자를 통해 인자로 받은 값을 Node의 값으로 할당해주고 최초 선언 시를 감안해 link에 0을 할당, 복수의 Node가 연결될 경우에는 link에 대한 값을 LinkedList 함수에서 처리
		  data = element;
		  link = 0;
		}
	};

template <class T> //class 및 function 앞 template 선언

class LinkedList{
	protected: //protected로 선언되었기 때문에 파생 클래스에서 this로 접근하지 않는 이상 manipulate가 불가능
		Node<T> *first; //LinkedList의 시작점, 즉 첫 번째 원소를 기리키는 값, 모든 iterate 작업은 이 값으로부터 시작
		int current_size; //GetSize 함수나 Print 함수에서 사용될 원소 개수를 저장, LinkedList의 특성상 그 이외의 함수에서는 불필요하므로 상황에 맞게 manual하게 조정
	public:
		LinkedList(){ //LinkedList의 생성자, Node가 없는 상태를 가정하기 때문에 NULL값을 first와 current_size 변수에 할당
			first = 0;
			current_size = 0;
		};
		int GetSize(){ //해당 인스턴스의 current_size 변수를 리턴
			return current_size;
		};
		void Insert(T element);		
		virtual bool Delete(T &element); //이후 파생 클래스 stack에서 overriding하므로 virtual로 선언
		void Print();
};

template <class T> //class 및 function 앞 template 선언

void LinkedList<T>::Insert(T element){ //첫 번째 원소의 위치에 새로운 원소를 할당
	Node<T> *newnode = new Node<T>(element); //새로운 원소를 Node class의 생성자를 통해 만들어주고 포인터 변수로 선언
	newnode -> link = first; //기존 첫 번째 원소가 두 번째 원소가 되기 때문에 새로운 첫 번째 원소인 newnode의 link를 first로 갱신
	first = newnode; //새로운 첫 번째 원소의 주소값을 LinkedList 인스턴스의 first 값에 할당
	current_size++; //manual로 1 증가
}

template <class T> //class 및 function 앞 template 선언
bool LinkedList<T>::Delete(T &element){ //가장 마지막 원소를 삭제, 즉 마지막 원소와 그 전 원소의 연결을 끊음
	if (first == 0) //원소가 없을 경우 delete 함수를 구현할 수 없음
		return false;
	
	Node<T> *current = first; //LinkedList 내의 Node들을 iterate하기 위해 임시로 선언한 두 변수
	Node<T> *previous = 0; //마지막 원소를 삭제하고 바로 전 원소를 마지막 원소로 갱신하는 작업에서 편의성을 위해 previous 변수도 선언
	
	while(1){ 
		if (current->link == 0){  //current가 마지막 원소를 가리킬 때, 즉 current가 마지막 원소를 가리킬 때
			if (previous) //previous가 0이 아니라면, 즉 원소가 2개 이상이라면
				previous -> link = current -> link; //마지막 원소와 그 전 원소의 연결을 끊는다
			else
				first = first -> link; //previous가 0이라면, 즉 원소가 1개라면 previous 값이 0이라서 사용할 수 없으므로 first 변수를 통해서만 처리, NULL값을 first에 할당하여 더 이상 원소가 존재하지 않음을 나타냄
			break; //current가 마지막 원소를 가리켰으므로 while문을 탈출
		}
		previous = current; //current가 아직 마지막 원소가 아니라면, 하나씩 증가
		current = current -> link; //리스트 내 원소의 순서는 previous > current > current->link
	}
	element = current -> data; //연결을 끊은 마지막 원소를 element 변수에 저장, 리턴할 경우를 대비
	delete current; //메모리 할당 해제
	current_size--; //manual로 1 감소

	return true;
}

template <class T> //class 및 function 앞 template 선언
void LinkedList<T>::Print(){ //차례대로 포인터값을 따라가 리스트 내의 원소들의 인덱스와 data를 출력
	Node<T> *i; //for문을 통해 iterate할 경우 새로운 변수가 필요하고 모든 연결이 Node class를 통해 이루어지므로 새로운 변수 할당
	int index = 1; //index값 초기화 및 첫 번째를 의미하는 1 할당

	if (current_size != 0){ //원소가 한 개라도 존재한다면
		for( i = first; i != NULL; i=i->link){ //first와 link값을 따라가 원소들을 iterate, link 값이 NULL, 즉 마지막일 때까지
			if (index == current_size){ //마지막 원소에 도착했을 경우, "->'는 불필요하므로 예외 처리
				cout << "[" << index << "|"; //해당 index를 출력
				cout << i -> data <<"]"; //해당 index에 맞는 Node의 값을 출력
			}			
			else { //그 외의 경우에는 다음 원소가 존재하므로 "->" formate을 추가시키고 index를 1씩 증가시킴
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}
}
#endif