### 解题思路
反转链表的时候，head->next会被一直改变，这点开始没想到

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
        if (m == 1) {
            ListNode * next = nullptr;
            
            return reverseN(head, n, next);;
        }
        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }

    ListNode* reverseN(ListNode* head, int n, ListNode*& next) {
       if (head == nullptr) {
           return nullptr;
       } 
       if (n == 1) {
           next = head->next;
           return head;
       }
       ListNode* tail = reverseN(head->next, n-1, next);

       head->next->next = head;
       head->next = next;
       return tail;  
    }
};
```