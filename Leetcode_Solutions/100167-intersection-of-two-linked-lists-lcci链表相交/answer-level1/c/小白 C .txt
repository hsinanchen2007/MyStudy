### 解题思路


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int la = 0, lb = 0;  //分别用来记录两个链表的长度
    int i = 0;
    struct ListNode *pa = headA, *pb = headB;
    //headA链表的长度
    while(pa){
        la++;
        pa = pa->next;
    }
    //headB链表的长度
    while(pb){
        lb++; 
        pb = pb->next;
    }
    pa = headA;
    pb = headB;
    //长链表先走la-lb或lb-la
    if(la > lb){
        for(i = 0; i < la-lb; i++){
            pa = pa->next;
        }
    }else{
        for(i = 0; i < lb-la; i++){
            pb = pb->next;
        }
    }
    //如果有公共节点，必定会相交
    while(pa && pb){
        if(pa == pb){
            return pb;
        }else{
            pa = pa->next;
            pb = pb->next;
        }
    }
    //没有公共节点返回NULL
    return NULL;
}
```