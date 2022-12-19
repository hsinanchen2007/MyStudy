```
struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* odd = head;
    struct ListNode* p = head;
    struct ListNode* next = NULL;
    if(p == NULL || p -> next == NULL){
        return head;
    }
    p = p ->next ->next;
    struct ListNode* even = head ->next;
    even -> next = NULL;
    int index = 3;
    while(p != NULL){
        if(index % 2 == 0){
            struct ListNode* tmp = even -> next;
            next = p ->next;
            even -> next = p;
            p ->next = tmp;
            even = p;
        }else{
            struct ListNode* tmp = odd -> next;
            next = p ->next;
            odd -> next = p;
            p ->next = tmp;
            odd = p;
        }
        index ++;
        p = next;
    }
    return head;  
}
```
