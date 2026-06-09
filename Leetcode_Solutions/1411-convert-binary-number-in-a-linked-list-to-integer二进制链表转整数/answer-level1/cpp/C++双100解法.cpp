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
    int getDecimalValue(ListNode* head) 
    {
        int ans = head -> val;
        while(head -> next)
        {
            ans = ans * 2 + head -> next -> val;
            head = head -> next;
        }
        return ans;

    }
};
```