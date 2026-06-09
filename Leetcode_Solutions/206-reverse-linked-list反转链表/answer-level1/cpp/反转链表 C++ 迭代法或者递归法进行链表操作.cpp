### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    // 递归
    ListNode* reverseList(ListNode* head) {
        // 头节点为空或者头节点没有下一个节点，结束
        if (!head || !head->next) return head;
        // 将头节点的下一个节点进行递归反转，每一次递归返回的节点就是最后反转过来的头节点。
        ListNode *prev = reverseList(head->next);
        // 由于是反转，使下一个节点的next指向头节点，头节点的next指向NULL
        head->next->next = head;
        head->next = NULL;
        return prev;
    }
    */
    
    // 迭代法，从前往后将链表顺序逆转
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        // curr它指向当前的头节点，从前往后循环指向每一个节点
        // pre指针指向curr的前驱节点，初始化指向NULL。
        ListNode *prev = NULL;
        ListNode *curr = head;
        // 进入循环，当curr指向最后一个节点时，值为null,则退出循环。
        while (curr != NULL) {
            // nextTemp是当前节点的后继，方便未来curr的变动。
            ListNode *nextTemp = curr->next;
            // 当前节点的nexe指针指向前驱节点
            curr->next = prev;
            // prev指针后移
            prev = curr;
            // curr指针后移
            curr = nextTemp;
        }
        return prev;
    }
    
    /*
    ListNode* reverseList(ListNode* head) {
        ListNode *p;
        for(p=NULL; head; swap(head,p))
            swap(p,head->next);
        return p;
    }
    */
};


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL) {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

int main() {
    ListNode node1(1); 
    ListNode node2(2); 
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode *head = &node1; 
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode *res = reverseList(head);
    while (res) {
        cout << res->val;
        if (res = res->next) cout << "->";
    }
}



```