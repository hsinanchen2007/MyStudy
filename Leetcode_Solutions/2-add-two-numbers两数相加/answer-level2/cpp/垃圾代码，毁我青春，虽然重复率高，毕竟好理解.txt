

### 代码
- 执行用时 :32 ms, 在所有 C++ 提交中击败了43.10% 的用户
- 内存消耗 :9.5 MB, 在所有 C++ 提交中击败了100.00%的用户
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
        ListNode* dummy = new ListNode(0);
        ListNode* it = dummy;
        int carry = 0;
        while(l1 || l2)
        {
            if(l1 == nullptr)
            {
                ListNode* temp = new ListNode(( l2->val + carry) % 10);
                it->next = temp;
                it = it->next;
                carry = ( l2->val + carry) / 10;
                l2 = l2->next;
                continue;
            }
            if(l2 == nullptr)
            {
                ListNode* temp = new ListNode(( l1->val + carry) % 10);
                it->next = temp;
                it = it->next;
                carry = ( l1->val + carry) / 10;
                l1 = l1->next;
                continue;
            }


            ListNode* temp = new ListNode((l1->val + l2->val + carry) % 10);
            it->next = temp;
            it = it->next;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry == 1)
        {
            ListNode* temp = new ListNode(carry);
            it->next = temp;
            it = it->next;
        }
        return dummy->next;
    }
};
```