//
//  main.cpp
//  11_Class_PointerExample
//
//  Created by 세광 on 2021/06/19.
//

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() : num(cnt++), ch('\0') { }
    
    void Check(MyClass *ptr) {
        // 포인터에 들어가는 값: obj 0번째 칸의 주소값(ptr = &obj[0] = obj)
        // ptr + num = &ptr[num] = &obj[num], obj의 num번째 칸에 있는 객체의 주소값과 동일
        if(ptr + num == this) {
            cout << num << endl;
        }
    }
    
    static int cnt;
    
private:
    int num;
    char ch;
};

int MyClass::cnt = 0;

int main() {
    MyClass obj[5];
    
    cout << "Test #1: " << endl;
    for(int i = 0; i < 5; i++) {
        obj[i].Check(obj); // obj를 매개변수로 넘겼다는 것은 obj의 0번째 칸의 주소값을 매개변수로 넘겼다는 의미(obj = &obj[0])
    }
    
    cout << "Test #2: " << endl;
    for(MyClass &i : obj) {
        i.Check(obj);
    }
    
    cout << "cnt = " << MyClass::cnt << endl;
}
