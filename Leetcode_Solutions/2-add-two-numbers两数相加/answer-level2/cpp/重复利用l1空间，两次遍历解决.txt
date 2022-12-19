### 解题思路
第一遍遍历链表将结果存到l1链表中，重复l1k空间，省内存，注意在这过程中不涉及进位
第二遍遍历l1，处理进位，
该方案从空间还是时间上来说都具有优势

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
        ListNode* result = l1;
        ListNode* temp = l1;
        while(l1->next && l2->next)
        {
            l1->val += l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->val += l2->val;
        if(l1->next == NULL)
            l1->next = l2->next;
        int add = 0;
        while(temp->next)
        {
            int value = temp->val + add;
            add = value/10;
            temp->val = value%10;
            temp = temp->next;
        }
        if(add+temp->val>=10)
        {
            ListNode * last = new ListNode((temp->val+add)/10);
            temp->val = (temp->val+add)%10;
            temp->next = last;
        }
        else
            temp->val = temp->val + add;
        return result;
    }
};
```