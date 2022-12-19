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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *prehead = new ListNode(0);
        ListNode *node = prehead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            node->next = new ListNode(sum);
            node = node->next;
        }

        if (carry != 0) {
            node->next = new ListNode(carry);
            node = node->next;
        }

        return prehead->next;
    }
};
```