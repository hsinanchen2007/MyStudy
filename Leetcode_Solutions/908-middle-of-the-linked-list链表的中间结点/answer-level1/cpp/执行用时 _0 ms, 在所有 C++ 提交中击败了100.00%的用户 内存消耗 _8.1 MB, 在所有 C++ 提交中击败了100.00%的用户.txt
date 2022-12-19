```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* temp=head->next;
        int size=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            size++;
        }
 
        int len=size/2;
        if(size%2!=0){len++;}


        temp=head;
        for(int i=0;i<len;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
};
```
