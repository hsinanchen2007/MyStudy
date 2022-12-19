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
    int kthToLast(ListNode* head, int k) 
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        --k;
        while(k)
        {
            p2 = p2 -> next;
            --k;
        }
        while(p2 -> next)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1 -> val;
    }
};
```