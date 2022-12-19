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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head -> next)
            return NULL;
        ListNode *left = head, *right = head, *del = NULL;
        int k = n;
        while(k--)
            right = right -> next;

        if(right != NULL)
            while(right -> next)
            {
                left = left -> next;
                right = right -> next;
            }
        else
        {
            head = head -> next;
            delete left;
            return head;
        }
        del = left -> next;
        left -> next = del -> next;
        delete del;
        return head;
    }
};
```