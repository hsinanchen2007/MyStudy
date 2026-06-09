### 解题思路

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
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        queue<int> q;
        ListNode* newhead=new ListNode(-1),*_newhead=newhead;

        while(head)
        {
            if(head->val<x) 
            {
                newhead->next=new ListNode(head->val);
                newhead=newhead->next;
            }
            else q.push(head->val);

            head=head->next;
        }        

        while(!q.empty())
        {
            newhead->next=new ListNode(q.front());
            newhead=newhead->next;
            q.pop();
        }

        return _newhead->next;
    }
};
```