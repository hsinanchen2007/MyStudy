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
    int kthToLast(ListNode* head, int k) {
        if(head->next==NULL) return head->val;
        ListNode*first=head;
        ListNode*last=head;
       // int n=k-1;
        while(k--)
        {
            first=first->next;
        }
        while(first)
        {
            first=first->next;
            last=last->next;
        }
        return last->val;
        

    }
};
```