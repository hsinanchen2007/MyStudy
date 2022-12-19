栈的解法
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        ListNode* ans = NULL;
        if(headA == NULL || headB == NULL)
        return ans;
        while(headA)
        {
            s1.push(headA);
            headA = headA -> next;
        }
        while(headB)
        {
            s2.push(headB);
            headB = headB -> next;
        }
        if(s1.top() == s2.top())
        {
        while(!s1.empty() && !s2.empty())
        {
            ans = s1.top();
            s1.pop();
            s2.pop();
            if(!s1.empty() && !s2.empty() && s1.top() != s2.top())
            {
                return ans;
            }
        }
        }
        return ans;    
    }
};
```