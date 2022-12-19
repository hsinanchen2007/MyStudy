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
    ListNode* swapPairs(ListNode* head) {
        //if(head == NULL || head->next == NULL)return head;
        
        
        ListNode* begin = new ListNode(0);
        //ListNode* begin1 = new ListNode(0);
        begin->next = head;
        ListNode* cur = begin;
        //ListNode* second = begin->next;
        while(cur->next && cur->next->next)
        {
            ListNode* first = cur->next;
            ListNode* second = first->next;
            cur->next = second;
            first->next = second->next;
            second->next = first;
            cur = first;
        }
        return begin->next;
    }
};
```