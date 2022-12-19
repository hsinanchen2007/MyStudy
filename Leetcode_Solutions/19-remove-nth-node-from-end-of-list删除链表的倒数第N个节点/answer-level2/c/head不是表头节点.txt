### 代码
head不是表头节点，踩坑了
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * tmp = head;     
    int len = 0;
    while(tmp) { len++; tmp = tmp -> next; }
    int pos = len - n;

    if(pos == 0) return head->next; // 第一个节点删除
    int j = 1;
    struct ListNode *curr = head;
    while(j < pos && curr){
        j++;
        curr = curr->next;
    }
    struct ListNode * p = curr;
    struct ListNode * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
```