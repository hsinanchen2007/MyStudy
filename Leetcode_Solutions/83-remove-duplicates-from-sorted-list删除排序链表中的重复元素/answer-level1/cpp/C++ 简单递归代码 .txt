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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        else{
            if(head->val==head->next->val)
            {
                head=deleteDuplicates(head->next);
                
            }
            else head->next=deleteDuplicates(head->next);
            return head;
        }
    }
};
```