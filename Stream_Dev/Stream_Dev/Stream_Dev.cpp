// Stream_Dev.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Stream.h"
#include "Flow.h"
int main()
{
    std::cout << "Hello World!\n"; 
	vector<float> v = {1,2,3,4,5,6};
	Stream<float> s(v);
	auto result = s
		.map([](float x)->float {return 1; })
		.map([](float x)->float {return x+3; })
		.reduce([](float x, float y)->float {return x + y; });
	cout << result;
	Flow<int> f;
	map<int> m([](int x)->int{return x + 3; });
	fillter<int> fil([](int x)->bool {return false; });
	f.next = m.flow();
	m.next = fil.flow();
	f.next->next;
}
