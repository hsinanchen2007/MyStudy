class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans=new ListNode(0);
        ListNode *pp=ans;
        ListNode* p[k];
        while(1)
        {
            for(int i=0;i<k;i++)
            {
                if(head!=nullptr)
                {
                    p[i]=head;
                    head=head->next;
                }
                else
                {
                    pp->next=p[0];
                    return ans->next;
                }
            }
            for(int i=0;i<k;i++)
            {
                pp->next=p[k-1-i];
                pp=pp->next;
            }
            if(head==NULL)return ans->next;
        }
    }
};

我这个在链表长的时候可以，短的时候不行，说是超出时间了，怎么修改呢。