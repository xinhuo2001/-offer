#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nptr) : val(x), next(nptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(cur != nullptr) {
            //反转
            cur->next = pre;
            //更新指针
            pre = cur;
            cur = next;
            if(cur) next = cur->next;
        }
        return pre;
    }
    //简洁写法
    ListNode* reverseList2(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        
        while(cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre; //反转
            //更新指针
            pre = cur;
            cur = next;
        }
        return pre;
    }
    //递归写法
    ListNode* reverseList2(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        //return值未曾变过 就是最后的节点处
        ListNode* node = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};


void test();
int main() {
    test();
    return 0;
}
void test()
{

}