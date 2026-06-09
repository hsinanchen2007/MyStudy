![capture_20191121233354794.bmp](https://pic.leetcode-cn.com/81e22e2bdd44a1dd5db83b0cb883d0716e668b8c5b27a9f1f8619808377a8d1a-capture_20191121233354794.bmp)

通过一次遍历，在一个循环体内完成链表段前后节点的保存、链表段的翻转，然后将翻转后的链表段重新挂接到原链表中。

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* p = head;
    struct ListNode* pre = NULL;
    struct ListNode* tmpHead = NULL;
    struct ListNode* tmpTail = NULL;

    for(int i = 0; i < n; i++) {
        struct ListNode* next = p->next;
        if (i == m-2) {
            pre = p;
        } 
        if (i >= m-1 && i < n) {
            if (i == m-1) {
                tmpTail = p;
            }
            p->next = tmpHead;
            tmpHead = p;
        } 
        p = next;
    }

    if(pre) {
        pre->next = tmpHead;
    } else {
        head = tmpHead;
    }
    tmpTail->next = p;

    return head;
}
```
