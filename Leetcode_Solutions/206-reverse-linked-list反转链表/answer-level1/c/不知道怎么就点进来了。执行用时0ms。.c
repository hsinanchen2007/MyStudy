##画图比较好理解。
##目的就是要让原先的next反转。

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = head;
        struct ListNode pre;
        pre.next = NULL;
        while(head)
        {
            head = head->next;
            cur->next = pre.next;
            pre.next = cur;
            cur = head;
        }
        return pre.next;

}
```