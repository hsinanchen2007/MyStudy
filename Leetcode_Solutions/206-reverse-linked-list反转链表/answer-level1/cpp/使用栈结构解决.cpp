### 解题思路
使用栈结构解决

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
    ListNode* reverseList(ListNode* head) 
    {
        stack<ListNode *> s;

        while(head != NULL)
        {
            s.push(head);
            head = head -> next;
        }

        ListNode r(0);
        ListNode *p = &r;

        while(!s.empty())
        {
            p -> next = s.top();
            s.pop();
            p = p -> next;
            p -> next = NULL;
        }

        return r.next;
    }
};
```