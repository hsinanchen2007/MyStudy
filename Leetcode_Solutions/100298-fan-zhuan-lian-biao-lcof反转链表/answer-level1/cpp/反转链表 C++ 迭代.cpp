### 解题思路
遍历链表，然后将遍历到的节点采用头插法插入到新链表中，的到的新链表即为反转链表

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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;   // 新的head，因为采用头插法，初始化应为空，因为在后续插入过程中该节点将变成末尾节点，即为空

        while(head){
            // 原链表的节点不为空时,将该节点插入到新链表的头节点
            ListNode* q = head;     // 指针q指向当前节点
            head = head->next;    // head指向下一个节点
            // 把q插入新链表的头节点
            q->next = newHead;
            newHead = q;            
        }

        return newHead;
    }
};
```