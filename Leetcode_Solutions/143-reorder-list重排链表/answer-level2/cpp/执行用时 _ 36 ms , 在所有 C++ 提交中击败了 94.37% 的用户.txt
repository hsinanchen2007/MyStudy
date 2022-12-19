### 解题思路
很明显的栈队列，一个先入先出， 一个先入后出

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
    void reorderList(ListNode* head) 
    {
        if(head == nullptr)
        {
            return;
        }
        queue<ListNode*>q;
        stack<ListNode*>s;
        int count = 0;
        while(head != nullptr)
        {
            ++count;
            q.push(head);
            s.push(head);
            head = head->next;
        }
        count >>=  1;
        ListNode* temp;
        ListNode* temp2;
        while(count)
        {
        
            temp = q.front();
            temp2 = s.top();
            temp2->next = temp->next;
            temp->next = temp2;
            q.pop();
            s.pop();
            --count;
        }
        temp = q.front();
        temp->next = nullptr;
        return;

    }
};
```