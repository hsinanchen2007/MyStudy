//  //* Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      struct ListNode *next;
//  };
 


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int data = 0;
    struct ListNode* l3   =   (struct ListNode*) calloc(1,sizeof(struct ListNode));
    struct ListNode* head = (struct ListNode*) calloc(1,sizeof(struct ListNode));


    if(!l3||!head)
    {
        return 0;
    }

       head = l3;
    while((l1!=NULL)||((l2)!=NULL)||data!=0)
    {
        //l3->next = NULL;
        
       if((l1!=NULL)||((l2)!=NULL))
        {
        if(l1==NULL) { 
        l3->val = (l2->val+data)%10;
        data = (l2->val+data)/10;
        l2=l2->next;
        }
        else if(l2==NULL){
        l3->val = (l1->val+data)%10;
        data = (l1->val+data)/10;
        l1=l1->next;
        }
        else
        {l3->val = (l1->val+l2->val + data)%10;
        data = (l1->val+l2->val+ data)/10;
        l1=l1->next;
        l2=l2->next;}

        if((l1!=NULL)||((l2)!=NULL)){
        l3 -> next = (struct ListNode*) calloc(1, sizeof(struct ListNode));
        l3=l3->next;}
    
        }
        else
        {
           l3 -> next = (struct ListNode*) calloc(1, sizeof(struct ListNode));
           l3=l3->next;

           l3->val = data;
           data = 0;

        }
       
    }
    

    return head;

}