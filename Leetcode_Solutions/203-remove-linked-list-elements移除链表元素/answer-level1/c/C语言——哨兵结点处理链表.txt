### 解题思路
关键点：找前继结点。
主要是头部情况复杂，可能会多次重复去除，所以难以找出真正的前结点。
于是我们声明一个空的前结点sentinel指向head，最终返回sentinel->next。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL) return NULL;
    struct ListNode *sentinel = (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinel->next=head;
    struct ListNode *prior=sentinel,*p=head;
    while(p!=NULL){
        if(p->val==val){    //双指针法
            prior->next=p->next;
            p=p->next;
        }else{
            prior=p;
            p=p->next;
        }
    }
    return sentinel->next;
}
```
总结：
    双指针法、哨兵结点对单向链表有奇效。尤其是需要找**前继结点**的算法。