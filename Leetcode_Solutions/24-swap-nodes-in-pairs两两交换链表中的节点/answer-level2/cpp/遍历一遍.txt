### 解题思路
定义一个新的链表头，用一个curHead指向当前剩下的链表，每次新链表先连上curHead的下一个，再连上curHead本身，再让curHead移动到后面即可。

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        if(head==nullptr) return newHead->next;
        ListNode* curHead = head;
        ListNode* rear = newHead;

        while(curHead!=nullptr && curHead->next!=nullptr){
            rear->next = curHead->next;//连上第二个
            ListNode* node1 = curHead;// 先保存第一个节点
            curHead = curHead->next->next; // 更新curHead
            rear->next->next = node1; //连上第一个
            rear = rear->next->next; // 更新新链表的尾结点指针
            rear->next = nullptr; // 让新链表的尾结点的next为空
        }
        if(curHead){
            rear->next = curHead;
        }
        return newHead->next;
    }
 
};
```