1.	思路
1）	遍历每个节点，直到p->next == NULL
2）	判断当前节点与下一节点的值是否一致，若一致，则删除下个节点，继续循环判断；否则，移动至下一节点。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *ptr = head;
    struct ListNode *temp = NULL;
    while (ptr != NULL && ptr->next != NULL) {
        if (ptr->next->val == ptr->val) {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        } else {
            ptr = ptr->next;
        }        
    }
    return head;
}
```
