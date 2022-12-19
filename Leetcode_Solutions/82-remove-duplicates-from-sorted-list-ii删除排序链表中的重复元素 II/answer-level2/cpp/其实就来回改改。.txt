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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode*p=head->next;
        ListNode*s=head;
        ListNode*q=head;
        ListNode*a=s;
        while(p)
        {
            if(p->val==s->val&&p==head->next&&s==head)
            {
                while(p->val==s->val)
                {
                     p=p->next;
                     s=s->next;
                     if(p==NULL)
                     break;
                }
                q=p;
                if(p)
                p=p->next;
                s=s->next;
                head->next=p;
                head=s;
            }
           else
           if(p->val==s->val)
            {
               while(p->val==s->val&&p)
               {
                     p=p->next;
                     if(p==NULL)
                     break;
                     }
               a->next=p;
               s=p;
               if(p)
               p=p->next;
            }
            else
            {
                a=s;
                s=s->next;
                p=p->next;
            }
        }
           return q;

    }
};
```