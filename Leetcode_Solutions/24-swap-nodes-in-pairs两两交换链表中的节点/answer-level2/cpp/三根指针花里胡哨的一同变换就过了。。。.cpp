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
        ListNode *p = new ListNode(0);
        p -> next = head;
        ListNode *q = head, *x = head;
        if(x && x -> next)
        {
            head = head -> next;
            x = x -> next;
        }
        else
            return head;
        
        while(x)
        {
            p -> next = x;
            q -> next = x -> next;
            x -> next = q;
            if(q -> next && q -> next -> next)
            {
                x = q -> next -> next;
                p = q;
                q = q -> next;
            }
            else
                return head;
        }
        return head;
    }
};
```