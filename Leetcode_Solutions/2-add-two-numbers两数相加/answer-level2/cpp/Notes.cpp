### 解题思路
注意返回的是res->next 并非res
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
        ListNode *res = new ListNode(0);
        ListNode *cur = res;
        int c_flag = 0;
        while(l1 != NULL || l2 != NULL){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + c_flag;
            c_flag = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(c_flag != 0) 
            cur->next = new ListNode(1);
        return res->next;
    }
};
```