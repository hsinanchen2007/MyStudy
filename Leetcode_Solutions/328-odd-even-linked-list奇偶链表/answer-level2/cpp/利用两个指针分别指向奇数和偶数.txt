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
    ListNode* oddEvenList(ListNode* head) {
         if(!head)   return nullptr;

        ListNode* p1 = head;
        ListNode* p2 = head->next;

        ListNode* tmp2 = head->next;//记录偶数链表的头结点
        while(p1!=NULL && p2!=NULL && p2->next!=NULL){
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }
        p1->next = tmp2;
        return head;
    }
};
```