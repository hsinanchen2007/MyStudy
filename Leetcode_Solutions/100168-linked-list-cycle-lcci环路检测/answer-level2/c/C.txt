```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    // 利用数学的知识来确定解决方案
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    slow = head;
    if(fast != NULL && fast->next != NULL){
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    return NULL;
}
```