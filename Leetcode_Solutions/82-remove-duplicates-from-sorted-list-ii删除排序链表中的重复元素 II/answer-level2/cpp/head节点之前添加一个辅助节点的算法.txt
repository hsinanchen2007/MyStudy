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
        if(head==NULL||head->next==NULL)  return head;
        ListNode *pre, *temp;//temp比pre慢一个位置；
        /* 预处理*/
        ListNode *prehead=new ListNode(INT_MAX);
        prehead->val=INT_MAX;
        prehead->next=head;
        pre=prehead;
        temp=pre->next; 
        while(temp->next!=NULL){ 
             if(temp->next->val!=temp->val)
             {
                 pre=pre->next;
                 temp=temp->next;
             }else{
                  while(temp->val==pre->next->val)
                  {   
                      if(temp->next==NULL){
                          pre->next=NULL;
                          return prehead->next;
                      }
                      temp=temp->next;
                  }
                  pre->next=temp;    
             }
           } 
        head=prehead->next;
        delete prehead;                                                return head;                                    
    }                                                                
};