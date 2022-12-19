### 解题思路
在原链表上更新节点值；2个链表长度不一致时将长的链到短的后面


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* tail = l1;
        int tmp = 0;
        int carry = 0;
        int val1 = 0;
        int val2 = 0;
        while ((p1 != NULL) || (p2 != NULL)) {		
            if (p2 == NULL) {
                val2 = 0;
                val1 = p1->val;
            } else if (p1->next == NULL) {
                p1->next = p2->next;
                p2->next = NULL;
                val1 = p1->val;
                val2 = p2->val;
            } else {
                val1 = p1->val;
                val2 = p2->val;
            }
            tmp = val1 + val2 + carry;
            p1->val = tmp % 10;            
            carry = tmp / 10;
            tail = p1;
            p1 = p1->next;
            if (p2 != NULL) p2 = p2->next;
        }
        if (carry != 0) {
            ListNode* carryNode = new ListNode(carry);
            tail->next = carryNode;
        }
        return l1;
    }
};
```