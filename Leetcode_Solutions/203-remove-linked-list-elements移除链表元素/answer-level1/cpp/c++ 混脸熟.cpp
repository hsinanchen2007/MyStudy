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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead = new ListNode(-1);    
        newhead->next = head;
        ListNode* tmp = newhead;
        while(tmp->next != NULL){
            if(tmp->next->val == val)tmp->next = tmp->next->next;
            else 
            tmp = tmp->next;
        }
        return newhead->next;
    }
};
```