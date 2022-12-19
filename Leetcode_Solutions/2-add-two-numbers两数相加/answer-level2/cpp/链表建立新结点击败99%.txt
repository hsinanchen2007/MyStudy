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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1, *pre = l1;
        int carry = 0;
        while(l1 && l2)
        {
            l1->val = l1->val + l2->val + carry;
            if(l1->val >= 10)
            {
                l1->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            l1->val += carry;
            if(l1->val >= 10)
            {
                l1->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            pre->next = new ListNode(l1->val);
            pre = pre->next;
            l1 = l1->next;
        }
        while(l2)
        {
            l2->val += carry;
            if(l2->val >= 10)
            {
                l2->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            pre->next = new ListNode(l2->val);
            pre = pre->next;
            l2 = l2->next;
        }
        if(carry)
            pre->next = new ListNode(1);
        return head;
    }
};
```