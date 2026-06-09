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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *pre=head;
        ListNode *cur=NULL;

        if (head == NULL)
        {
            return NULL;
        }
        while (pre != NULL)
        {
            ListNode *t=pre->next;
            pre->next=cur;
            cur=pre;
            pre=t;
        }
        return cur;
    }
};
```