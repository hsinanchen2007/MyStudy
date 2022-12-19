刚看到这个题的时候，我的想法有点暴力，但是看到解答区这个方法，觉得很灵活，从头尾两头分别进行头插法和尾插法
```
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
    ListNode* partition(ListNode* head, int x) {
        if(!head)    return head;
        ListNode *ans=head;
        ListNode *tail=head;
        ListNode *mark=head->next;
        while(mark)
        {
            ListNode *p=mark;
            mark=mark->next;
            if(p->val<x)
            {
                p->next=ans;
                ans=p;   
            }
            else
            {
                tail->next=p;
                tail=p;
            }
        }
        tail->next=NULL;
        return ans;
        
    }
};
```
