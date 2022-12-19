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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)return nullptr;
        ListNode *dummy = new ListNode(0);  //哑节点
        ListNode *temp1 = l1, *temp2 = l2, *dark = dummy;
        while(temp1 && temp2)
        {
            if(temp1->val < temp2->val)
            {
                dark->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            }
            else
            {
                dark->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            dark = dark->next;
        }
        while(temp1)
        {
            dark->next = new ListNode(temp1->val);
            temp1 = temp1->next;
            dark = dark->next;
        }
        while(temp2)
        {
            dark->next = new ListNode(temp2->val);
            temp2 = temp2->next;
            dark = dark->next;
        }
        return dummy->next;
    }
};
```