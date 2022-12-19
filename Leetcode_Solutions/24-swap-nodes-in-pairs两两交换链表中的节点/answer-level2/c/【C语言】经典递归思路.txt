```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    
    if(head==NULL||head->next==NULL){  //剩余一个或0个节点不交换，直接返回head
        return head;
    }
    
    struct ListNode* tmp;
    
    tmp = head->next;
    
    head->next = swapPairs(tmp->next);  // head后继节点指向剩余节点, 递归最关键的一步
    
    tmp->next = head; // head交换成为第二个节点
        
    //head->next->next = p;
    
    // head->next = swapPairs(head->next->next);
    
    return tmp;
}

```

