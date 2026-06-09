### 解题思路
双指针 一个先走k步， 再同时走，直到先走的为null

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        
        ListNode* p1 = head;
        ListNode* p2 = head;

        for(int i = 0; i < k; ++i)
        {
            p1 = p1->next;
        }

        while(p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};
```