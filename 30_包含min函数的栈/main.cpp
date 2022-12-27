#include<iostream>
#include<stack>
using namespace std;
const int stack_len = 100;

class MinStack {
private:
    int dataStack[stack_len]; //存放数据
    int dataPtr; //数据栈指针
    int minNumStack[stack_len];//存放当前最小值
    int minNumPtr; //最小值栈指针
    int minNum; //当前遇到的最小值
public:
    /** initialize your data structure here. */
    MinStack() {
        dataPtr = 0;
        minNumPtr = 0;
        minNum = 0x7fffffff; //最大值
    }
    
    void push(int x) {
        if(dataPtr < stack_len) {
            dataStack[dataPtr++] = x;
            //遇到更小值 存入minNumStack
            if(x <= minNum) {
                minNumStack[minNumPtr++] = x;
                minNum = x;
            }
        } else {
            cout << "stack is full" << endl;
        }
    }
    
    void pop() {
        if(dataPtr > 0) {
            //数据出栈
            dataPtr--;
            //如若当前是出栈的是最小值 最小值栈也出栈
            if(dataStack[dataPtr] == minNum) {
                minNumPtr--;
                //更新MinNum
                if(minNumPtr > 0) {
                    minNum = minNumStack[minNumPtr-1];
                } else {
                    minNum = 0x7fffffff;
                }
            }
        } else {
            cout << "stack is empty" << endl;
        }
    }
    
    int top() {
        if(dataPtr > 0) {
            return dataStack[dataPtr-1];
        } else {
            return -1;
        }
    }
    
    int min() {
        if(minNumPtr > 0) {
            return minNumStack[minNumPtr-1];
        } else {
            return 0;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */


void test();
int main() {
    test();
    return 0;
}
void test()
{
    MinStack* obj = new MinStack();
    obj->push(3);
    cout << obj->top() << endl;
    cout << obj->min() << endl;
    obj->push(5);
    cout << obj->top() << endl;
    cout << obj->min() << endl;
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->min() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->min() << endl;
}