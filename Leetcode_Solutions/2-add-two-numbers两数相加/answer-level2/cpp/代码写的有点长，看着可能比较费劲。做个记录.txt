### 解题思路
写的乱糟糟的，太久没做题了。

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
        ListNode *start = new ListNode(0);
        if(l1 == NULL && l2 ==NULL)
        {
            return start;
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int num1;
        int num2;
        int sum = 0;
        int flag = 0;
        
        if(p1!=NULL)
        {
            num1 = p1->val;
            p1 = p1->next;
        } 
        else
        {
            num1 = 0;
        }
        if(p2!=NULL)
        {
            num2 = p2->val;
            p2 = p2->next;
        }
        else
        {
            num2 = 0;
        }
        sum = num1 + num2;
        start->val = sum%10;
        flag = sum/10;
        ListNode *cur = start;
        while(p2 != NULL||p1!=NULL)
        {
            cur->next = new ListNode(0);
            cur = cur -> next;
            if(p1 != NULL)
            {
                num1 = p1->val;
                p1 = p1->next;
            }
            else
            {
                num1 = 0;
            }
            if(p2!=NULL)
            {
                num2 = p2->val;
                p2 = p2->next;
            }
            else
            {
                num2 = 0;
            }
            sum = num1 + num2 + flag;
            cur->val = sum%10;
            flag = sum/10;
        }
        if(flag!=0)
        {
            cur->next = new ListNode(1);
            cur = cur -> next;
        }
        cur->next = NULL;
        return start;
        
    }
};
```