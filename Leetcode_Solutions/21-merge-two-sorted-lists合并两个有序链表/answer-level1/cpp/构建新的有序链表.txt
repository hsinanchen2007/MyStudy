### 解题思路链表里面只能通过->next来遍历，通过迭代的方式来做

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
        ListNode* head=new ListNode(1);
        ListNode* res=head;
        while (l1!=NULL && l2!=NULL)
        {
            if (l1->val<l2->val)
            {
                head->next=l1;
                l1=l1->next;
            }
            // else if (l1->val>l2->val)
            // {
            //     head->next=l2;
            //     l2=l2->next;
            // }
            else 
            {
                // head->next=l2;
                // head=head->next;
                // head->next=l1;
                // l1=l1->next;
                // l2=l2->next;
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        %剩下一条链表不是空的
        if (l1!=NULL){
            head->next=l1;
        }
        if (l2!=NULL){
            head->next=l2;
        }
        return res->next;
    }
};
```