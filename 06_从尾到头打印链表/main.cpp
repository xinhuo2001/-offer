#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nptr) : val(x), next(nptr) {}
};

class Solution {
public:
    ListNode* head;
public:
    Solution() {
        //构造一个初始链表
        head = new ListNode(1);
        ListNode* tem = head;
        //注入其他数据
        for(int i = 2; i <= 4; i++) {
            ListNode* node = new ListNode(i);
            tem->next = node;
            tem = tem->next;
        }
    }

    //打印链表
    void showList(ListNode* h) {
        while(h != nullptr) {
            cout << h->val << " ";
            h = h->next;
        }
        cout << endl;
    }

    //反转链表
    ListNode* reverseList(ListNode* h) {
        ListNode* pre = nullptr;
        ListNode* cur = h;
        ListNode* next = h->next;
        while(cur != nullptr) {
            //反转
            cur->next = pre;
            //重置指针位置
            pre = cur;
            cur = next;
            if(cur != nullptr)
                next = cur->next;
        }
        return pre;
    }

    vector<int> reversePrint(ListNode* head) {
        //反转链表
        head = this->reverseList(head);
        vector<int> res;
        res.clear();
        ListNode* tem = head;
        while(tem != nullptr) {
            res.push_back(tem->val);
            tem = tem->next;
        }
        head = this->reverseList(head);
        return res;
    }

    //递归
    vector<int> reversePrint1(ListNode* head) {
        if(head == nullptr) return {};

        vector<int> res = reversePrint1(head->next);
        res.push_back(head->val);
        
        return res;
    }

    //栈 顺序遍历入栈 然后依次出栈
    vector<int> reversePrint2(ListNode* head) {
        if(head == nullptr) return {};
        vector<int> res;
        stack<int> s;
        while(head != nullptr) {
            s.push(head->val);
            head= head->next;
        }
        while(s.empty() == false) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};


void test();
int main() {
    test();
    return 0;
}
void test()
{
    Solution* sptr = new Solution();
    sptr->showList(sptr->head);
    sptr->head = sptr->reverseList(sptr->head);
    sptr->showList(sptr->head);
}