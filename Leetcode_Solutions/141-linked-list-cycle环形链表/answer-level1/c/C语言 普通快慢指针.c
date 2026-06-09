```
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast != NULL && slow->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}
```
