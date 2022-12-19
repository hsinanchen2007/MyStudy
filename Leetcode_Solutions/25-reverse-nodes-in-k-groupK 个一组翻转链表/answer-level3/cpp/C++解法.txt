```
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head,int k)
    {
        if(!head) return nullptr;
        if(k <= 1) return head;
        ListNode *newhead = nullptr,*curr = head,
            *tmp,*tmphead = nullptr,*tail = nullptr;
        int len = 0;
        while(curr) 
        {
            len++;
            curr = curr->next;
        }
        int m = len/k;
        if(m == 0) return head;
        int j = 0,times = 1;
        while(head)
        {
            if(0 == j) tail = head;
            tmp = head;
            head = head->next;
            tmp->next = tmphead;
            tmphead = tmp;
            j++;
            if(j >= k)
            {
                if(!newhead)
                {
                    newhead = tmphead;
                }
                else
                {
                    curr->next = tmphead;
                }
                curr = tail;
                j = 0;
                times++;
                tmphead = nullptr;
                if(times > m)
                {
                    curr->next = head;
                    break;
                }
            }
        }
        return newhead;
    }
};
```
