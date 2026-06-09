struct ListNode* partition(struct ListNode* head, int x){
    if(head==NULL)
        return head;
    struct ListNode*newnode1,*newnode2,*newnode3,*newnode4,*output;
    output=(struct ListNode*)malloc(sizeof(struct ListNode));
    output=NULL;
    newnode1=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode2=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode3=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode4=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode3->val=x;
    newnode3->next=NULL;
    newnode4=newnode3;
    newnode1=head;
    newnode2=newnode3;
    int k=0;
    for(newnode1=head;newnode1;newnode1=newnode1->next)
    {
        
        if(newnode1->val>=x)
        {
            struct ListNode*newnode;
            newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=newnode1->val;
            newnode->next=NULL;
            newnode3->next=newnode;
            newnode3=newnode;
            continue;
        }
        else if(newnode1->val<x&&k==0)
        {
            struct ListNode*newnode;
            newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=newnode1->val;
            newnode->next=newnode2;
            newnode2=newnode;
            output=newnode;
            k++;
            continue;
        }
         else if(newnode1->val<x&&k==1)
        {
            struct ListNode*newnode;
            newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=newnode1->val;
            newnode->next=newnode4;
            newnode2->next=newnode;
            newnode2=newnode;
            continue;
        }
    }
    if(output!=NULL)
        newnode2->next=newnode4->next;
    else
        output=newnode2->next;
    
    return output;
}
