### 解题思路
* 不提前遍历判断长短
* 进位carry提前加到l1
* 先遍历l1，保持tmp1是最后一个结点值；然后遍历l2
* 最后一位可能会产生进位，对值进行判断，然后对carry判断

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
        int carry = 0;
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        for(; tmp1->next; tmp1 = tmp1->next) {   // 累加到l1上，tmp1->next非空即最后一个值
            int sum = 0;
            if(tmp2 == NULL)    sum = tmp1->val;    // l1是较长链的情况
            else {
                sum = tmp1->val + tmp2->val;
                tmp2 = tmp2->next;
            }
            carry = sum / 10;
            tmp1->val = sum % 10;
            tmp1->next->val += carry;
        }
        carry = 0;
        for(; tmp2; tmp2= tmp2->next) {     // l2是较长链的情况，l1需要新建结点，tmp2非空即最后空结点
            int sum = tmp1->val + tmp2->val;
            carry = sum / 10;
            tmp1->val = sum % 10;
            if(tmp2->next)  {
                tmp1->next = new ListNode(0);
                tmp1 = tmp1->next;
                tmp1->val += carry;
            }
        }
        if(tmp1->val > 9) {
            carry = tmp1->val / 10;
            tmp1->val = tmp1->val % 10;
        }
        if(carry == 1) {
            tmp1->next = new ListNode(1);
        }
        return l1;
    }
};
```
![1.png](https://pic.leetcode-cn.com/02e122b7e456a45f8fcc6ee1c28bd5ab5036ca1307f4e075f1965966a9ac07d2-1.png)
