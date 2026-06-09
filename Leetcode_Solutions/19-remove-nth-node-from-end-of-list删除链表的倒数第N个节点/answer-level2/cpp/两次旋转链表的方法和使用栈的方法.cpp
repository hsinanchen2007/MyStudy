两种方法都可以通过设置哑结点来减少判断。
```
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* InverseList(ListNode* head)
    {
        ListNode *p,*q,*r;
        p=head;
        if(p==NULL) return head;
        q=head->next;
        p->next=NULL;
        if(q==NULL)return head;
        r=q->next;
        while(r)
        {
            q->next=p;
            p=q;
            q=r;
            r=r->next;
        }
        q->next=p;

        return q;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return head->next;

        ListNode *ans,*reverse_head,*pre,*temp;
        reverse_head=InverseList(head);
        temp=reverse_head;
        
        //指向要删除的结点，保存前一个结点信息
        if(n==1)
        {
            reverse_head=reverse_head->next;
        }
        else
        {
            while(n-1)
            {
                pre=temp;
                temp=temp->next;
                n--;
            }
            pre->next=temp->next;
        }
        ans=InverseList(reverse_head);

        return ans;
    }
};
```

```
 #include <iostream>
            #include <stack>
            using namespace std;
            class Solution {
            public:
                ListNode* removeNthFromEnd(ListNode* head, int n)
                {
                    if(head->next==NULL) return head->next; 

                    stack<ListNode*>s;
                    ListNode *p,*q,*node;
                    node=head;
                    while(node)
                    {
                        s.push(node);
                        node=node->next;
                    }
                    while(n)
                    {
                        p=s.top();
                        s.pop();
                        --n;
                    }
                    if(s.empty())
                    {
                        return p->next;
                    }
                    else
                    {
                        q=s.top();
                        q->next=p->next;
                    }
                    
                    return head;
                }
            };
```

