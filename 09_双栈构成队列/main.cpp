#include<iostream>
#include<stack>
using namespace std;

class CQueue {
private:
    //inStack 用于存数 outStack用于出数
    stack<int> inStack,outStack; 
public:
    CQueue() {
        // cout << "null ";
    }
    
    void appendTail(int value) {
        this->inStack.push(value);
        // cout << "null ";
    }
    
    int deleteHead() {
        //outStack不空直接出数
        if(outStack.empty() == false) {
            int outVal = this->outStack.top();
            this->outStack.pop();
            return outVal;
        } else if(inStack.empty() == false) {
            //inStack不空则转移到outStack
            while(!inStack.empty()) {
                int temVal = inStack.top();
                inStack.pop();
                outStack.push(temVal);
            }
            int outVal = this->outStack.top();
            this->outStack.pop();
            return outVal;
        } else {
            //无数据返回-1
            return -1;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */


void test();
int main() {
    test();
    return 0;
}
void test()
{
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    int param_2 = obj->deleteHead();
    cout << param_2 << " ";
    param_2 = obj->deleteHead();
    cout << param_2 << " ";
}