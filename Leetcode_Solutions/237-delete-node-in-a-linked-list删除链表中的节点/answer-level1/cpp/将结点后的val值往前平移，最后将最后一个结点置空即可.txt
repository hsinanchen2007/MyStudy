class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next!=NULL){
            node->val=node->next->val;
            if(node->next->next==NULL){node->next=NULL;break;}
             node=node->next;
        }
    }
};