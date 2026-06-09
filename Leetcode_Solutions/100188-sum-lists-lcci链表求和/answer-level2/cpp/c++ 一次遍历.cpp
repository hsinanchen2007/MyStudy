### 解题思路
正常思路
循环退出后不要忘记判断最后的dlt。

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
        int dlt = 0;
        ListNode* result = new ListNode(0);
        ListNode* p = result;
        while (l1 || l2) {
            if (l1) dlt += l1->val;
            if (l2) dlt += l2->val;
            p->next = new ListNode(dlt%10);
            p = p->next;
            dlt /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (dlt) p->next = new ListNode(dlt);
        return result->next;
    }
};
```