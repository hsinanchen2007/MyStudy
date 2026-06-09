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
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        ListNode* pre = new ListNode(0);
        int carry = 0;
        pre->val = l1->val + l2->val + carry;
        l1 = l1->next;
        l2 = l2->next;
        if(pre->val >= 10)
        {
            pre->val %= 10;
            carry = 1;
        }
        else
            carry = 0;
        ListNode* ansH = pre;
        while(l1 != NULL && l2 != NULL)
        {
            ListNode* node = new ListNode(0);
            node->val = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            if(node->val >= 10)
            {
                node->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            pre->next = node;
            pre = node;
        }
        while(l1 != NULL)
        {
            ListNode* node = new ListNode(0);
            node->val = l1->val + carry;
            l1 = l1->next;
            if(node->val >= 10)
            {
                node->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            pre->next = node;
            pre = node;
        }
        while(l2 != NULL)
        {
            ListNode* node = new ListNode(0);
            node->val = l2->val + carry;
            l2 = l2->next;
            if(node->val >= 10)
            {
                node->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            pre->next = node;
            pre = node;
        }
        if(l1 == NULL && l2 == NULL && carry == 1)
        {
            ListNode* node = new ListNode(carry);
            pre->next = node;
            pre = node;
        }
        pre->next = NULL;
        return ansH;
    }
};
```