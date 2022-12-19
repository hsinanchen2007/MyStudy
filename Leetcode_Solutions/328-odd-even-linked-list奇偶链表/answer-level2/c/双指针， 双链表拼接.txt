### 解题思路
一开始想到使用快慢指针， 但是后来发现使用快慢指针将会导致偶数节点的顺序变化。
所以这里可以将原链表拆分为两个链表， 一个是奇数链表， 一个是偶数链表， 循环完毕后则将奇数链表的尾部与偶数链表头部相连。
循环时， 偶数链表比奇数链表更加靠近链表尾部， 当偶数链表指向 NULL 或者其 next == NULL 代表偶数链表循环结束， 并且后方也不再有奇数链表， 循环结束.
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* oddHeah = head; // 保存奇数u偶数链表头部
    struct ListNode* oddNode = oddHeah;
    struct ListNode* evenHeah = head -> next;
    struct ListNode* evenNode = evenHeah;
    while(evenNode != NULL && evenNode -> next != NULL){
        oddNode -> next = oddNode -> next -> next;
        evenNode -> next = evenNode -> next -> next;
        oddNode = oddNode -> next;
        evenNode = evenNode -> next;
    }
    oddNode -> next = evenHeah; // 拼接链表， 循环结束时 oddNode 指向奇数链表最后一个元素
    return oddHeah;
}
```