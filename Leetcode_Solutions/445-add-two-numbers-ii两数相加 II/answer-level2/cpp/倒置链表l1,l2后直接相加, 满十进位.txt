### 解题思路
此处撰写解题思路
![2020-01-07_190941.png](https://pic.leetcode-cn.com/35b8b91f46a95c83bb48d0954584b63290c291c740e0d2ccd4dcea4a07392bf9-2020-01-07_190941.png)
int t = 0;
当前位的数值：t+=l1->val+l2->val;--->t%10
进位：t=t/10;
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *cur=head;
        while(cur)
        {
            ListNode *t=cur->next;
            cur->next=pre;
            pre=cur;
            cur=t;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode* h=new ListNode(0);
        int t=0;
        while(l1&&l2)
        {
            t +=l1->val+l2->val;
            ListNode *n=new ListNode(t%10);
            n->next=h->next;
            h->next=n;
            t=t/10;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1)
        {
            while(l1)
            {
                t +=l1->val;
                ListNode *n=new ListNode(t%10);
                n->next=h->next;
                h->next=n;
                t=t/10;
                l1=l1->next;
            }
        }
        if(l2)
        {
            while(l2)
            {
                t +=l2->val;
                ListNode *n=new ListNode(t%10);
                n->next=h->next;
                h->next=n;
                t=t/10;
                l2=l2->next;
            }
        }
        if(t>=1)
        {
            ListNode *n=new ListNode(t);
            n->next=h->next;
            h->next=n;
        }
        return h->next;
    }
};
```