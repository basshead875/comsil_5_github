#include <stdio.h>
#include "Stack.h"

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"자료구조 선택(1: Stack, Other: Linked List): "; //실행시키면 나오는 첫 번째 창, stdin을 mode에 할당하여 이후 진행
		cin>>mode;
						    
		if(mode == 1)
			p = new Stack<int>();    //1일 경우 LinkedList의 파생 클래스인 Stack 호출			
		else
			p = new LinkedList<int>(); //그 외의 경우 LinkedList 호출

		do{ //flag를 통해 탈출문이 나오는 경우 외에는 계속해서 proMenu 함수를 구동
			prnMenu();
			cin>>selectNumber; //stdin을 통해 값을 입력받음
			
			switch(selectNumber){ 
				case 1: //삽입의 경우, Insert 함수를 호출하여 stdin으로 받은 값을 인자로 넣어주고 함수 작동 이후에는 cout를 사용하여 어떠한 작업을 했는지 안내
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem);
					cout<<tmpItem<<"가 삽입되었습니다."<<endl;
					break;
					
				case 2: //삭제의 경우, delete 함수를 구동하고, 해당 함수가 false를 리턴한다면 해당 인스턴스에 아무 원소도 없다는 것을 안내
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
						
					else cout<<"비어있습니다. 삭제 실패"<<endl;
					break;
					
				case 3: //출력의 경우, GetSize 함수를 통해 해당 인스턴스의 current_size 값을 출력
					cout<<"크기: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4: //종료의 경우, 기존 flag 변수를 false로 초기화한 후, 해당 메뉴 선택 시 true로 변경
					flag = true;     break;
					
				default: //그 외의 경우, 에러 메시지 출력
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			
			}
			
			if(flag) break; //만약 4.종료를 통해 flag가 true로 바뀌었다면 do while문 탈출
			
		} while(1);
		
		return 0;
}

