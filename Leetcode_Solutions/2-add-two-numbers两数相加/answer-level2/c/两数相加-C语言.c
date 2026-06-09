
C语言实现：

```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre->val = 0;
    pre->next = NULL;
    
    struct ListNode* cur = pre;
    int carry = 0;
    int sum = 0;
    
    while(l1 != NULL || l2 != NULL){
        int x = (l1 == NULL) ? 0:l1->val;
        int y = (l2 == NULL) ? 0:l2->val;
        
        sum = x + y + carry;
        carry = sum / 10;
        
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = sum % 10;
        p->next = NULL;
            
        cur->next = p;
        cur = cur->next;
        
        if(l1 != NULL){
            l1 = l1->next;
        }
        if(l2 != NULL){
            l2 = l2->next;
        }
    }
    
    if(carry == 1){
        struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
        ca->val = carry;
        ca->next = NULL;
        cur->next = ca;
    }    
        
    return pre->next; 
}
```


