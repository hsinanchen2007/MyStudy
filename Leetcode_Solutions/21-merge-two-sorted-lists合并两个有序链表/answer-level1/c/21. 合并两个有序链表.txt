### 解题思路
创建一个不放实际值的头结点，用两个指针来遍历所给的两个链表，把值小的放到咋们的sum链表中，并使对于链表的指针往后移

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* p1, struct ListNode* p2){
    struct ListNode* t;
    struct ListNode* sum = (struct ListNode*)malloc(sizeof(struct ListNode));
    t = sum;
    while(p1 != NULL && p2 !=NULL){
        if(p1->val<=p2->val){
            t->next = p1;
            p1 = p1->next;
            t = t->next;
        }
        else{
            t->next = p2;
            p2 = p2->next;
            t = t->next;
        }
    }
    if(p1 != NULL)
        t->next = p1;
    else
        t->next = p2;
    return sum->next;
}
```