### 解题思路
双指针

### 代码

## ```cpp
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
        int i= 0;
        while(i < k)
        {
            p1 = p1->next;
            i++;
        }
        while(p1 != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
```