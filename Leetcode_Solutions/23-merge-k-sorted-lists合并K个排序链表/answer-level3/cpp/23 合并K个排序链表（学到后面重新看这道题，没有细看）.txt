方法一：逐一两两合并链表：通过两个链表的合并，循环求出K个链表的合并


```
class Solution {
public:
    ListNode* mergetwolist(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        if(l1->val<l2->val)
        {
            l1->next=mergetwolist(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergetwolist(l1,l2->next);
            return l2;
        }
    }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* cur=NULL;
        for(vector<ListNode*>::iterator it=lists.begin();it!=lists.end();it++)
        {
            cur=mergetwolist(cur,*it);
            
        }
        return cur;
    }
};
```
