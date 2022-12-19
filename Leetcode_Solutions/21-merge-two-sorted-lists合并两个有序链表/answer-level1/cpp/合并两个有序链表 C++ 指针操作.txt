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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 头节点
        ListNode newHead(0);
        // pi指针指向头节点，用以指针操作
        ListNode *pi = &newHead;
        while(l1 && l2) {
            // 如果l1节点的值大于l2节点的值，交换节点，l1永远指向较小的那个，每次循环都是l1被加进pi的链表里
            if (l1->val > l2->val) swap(l1, l2);
            // pi节点的next指针指向l1节点，
            pi->next = l1;
            // l1指针指向下一个节点
            l1 = l1->next;
            // pi指针移动到下一个节点
            pi = pi->next;
        }
        // 当l1或l2有一个指向null了，把另一个的加进pi链表里
        pi->next = l1 ? l1 : l2;
        return newHead.next;
    }
};


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode newHead(0);
    ListNode *pi = &newHead;
    while(l1 && l2) {
        if (l1->val > l2->val) swap(l1, l2);
        pi->next = l1;
        l1 = l1->next;
        pi = pi->next;
    }
    pi->next = l1 ? l1 : l2;
    return newHead.next;
}

int main() {
    ListNode node1(1); ListNode node2(2); ListNode node3(4);
    ListNode *l1 = &node1; node1.next = &node2; node2.next = &node3;
    ListNode node4(1); ListNode node5(3); ListNode node6(4);
    ListNode *l2 = &node4; node4.next = &node5; node5.next = &node6;
    ListNode *res = mergeTwoLists(l1, l2);
    while (res) {
        if (res->next) cout << res->val << "->";
        else cout << res->val;
        res = res->next;
    }
}



```