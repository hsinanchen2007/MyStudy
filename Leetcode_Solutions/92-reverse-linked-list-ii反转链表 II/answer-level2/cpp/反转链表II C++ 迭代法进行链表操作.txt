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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 头节点指针、左节点指针、右节点指针
        ListNode dummyHead(-1), *left;
        dummyHead.next = head;
        left = &dummyHead;
        // 左指针指向第m个节点的前一个节点
        for (int i=0; i<m-1; i++) {
            left = left->next;
        }
        // 迭代法，从前往后将链表顺序逆转
        head = left->next;
        for (int i=0; i<n-m; i++) {
            ListNode *temp = head->next;
            head->next = temp->next;
            temp->next = left->next;
            left->next = temp;
        }
        return dummyHead.next;
    }
};



#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummyHead(-1), *left;
    dummyHead.next = head;
    left = &dummyHead;
    for (int i=0; i<m-1; i++) {
        left = left->next;
    }
    head = left->next;
    for (int i=0; i<n-m; i++) {
        ListNode *temp = head->next;
        head->next = temp->next;
        temp->next = left->next;
        left->next = temp;
    }
    return dummyHead.next;
}

int main() {
    ListNode node1(1); ListNode node2(2); ListNode node3(3); 
    ListNode node4(4); ListNode node5(5); 
    ListNode *head = &node1; node1.next = &node2; node2.next = &node3; 
    node3.next = &node4; node4.next = &node5;
    ListNode *res = reverseBetween(head, 2, 4);
    while (res) {
        if (res->next) cout << res->val << "->";
        else cout << res->val;
        res = res->next;
    }
}




```