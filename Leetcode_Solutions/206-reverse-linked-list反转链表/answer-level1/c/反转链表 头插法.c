### 解题思路
使用头插法，每次都将结点插入到链表尾部，即可完成反转链表

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p;
    struct ListNode *r;
    p=NULL;r=head;
    
    while(r!=NULL){
        head=head->next;
        r->next=p;
        p=r;
        r=head;
    }
    head=p;
    return head;   
}
```