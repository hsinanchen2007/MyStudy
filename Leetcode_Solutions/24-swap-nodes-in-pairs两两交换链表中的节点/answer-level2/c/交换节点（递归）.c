```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* nextNode = NULL;
    struct ListNode* tmpNode = NULL;

    if (head == NULL || head->next == NULL) {
        return head;
    }
    nextNode = head->next;
    tmpNode = swapPairs(nextNode->next);
    nextNode->next = head;
    head->next = tmpNode;
    return nextNode;
}
```
