### 解题思路
没有什么解题思路，就是利用链表复现加法罢l，而且很巧的是对于单链表放置而言，小位在head区就很方便。

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
        struct ListNode* a=new ListNode();
        struct ListNode* n=a;
        struct ListNode* pre=a;
        int carry=0;
        while(l1!=NULL &&l2!=NULL)
        {
            int ans=l1->val+l2->val+carry;
            carry=ans/10;
            ans=ans%10;
            n->val=ans;
            struct ListNode* tmp=new ListNode();
            n->next=tmp;
            pre=n;
            n=tmp;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=NULL)
        {
            while(l1!=NULL)
            {
                int ans=l1->val+carry;
                carry=ans/10;
                ans=ans%10;
                n->val=ans;
                struct ListNode* tmp=new ListNode();
                n->next=tmp;
                pre=n;
                n=tmp;
                l1=l1->next;
            }
        }
        else if(l2!=NULL)
        {
            while(l2!=NULL)
            {
                int ans=l2->val+carry;
                carry=ans/10;
                ans=ans%10;
                n->val=ans;
                struct ListNode* tmp=new ListNode();
                n->next=tmp;
                pre=n;
                n=tmp;
                l2=l2->next;
            }
        }
        if(carry!=0)
        {
            n->val=carry;
        }
        else{
            pre->next=NULL;
        }
        return a;
    }
};
```