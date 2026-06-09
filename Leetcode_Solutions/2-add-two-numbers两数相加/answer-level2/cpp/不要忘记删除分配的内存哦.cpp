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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 == NULL && l2 == NULL) return NULL;
        
        ListNode *head = new ListNode(-1);
        ListNode *mov = head;
        int carry = 0;
        while(l1 || l2)
        {
            int sum = 0;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum >= 10 ? 1 : 0;

            mov->next = new ListNode(sum % 10);
            mov = mov->next;
        }

        if(carry) mov->next = new ListNode(carry);

        ListNode *res = head->next;
        delete head;
        return res;


    }
};
```