### 解题思路
题解双100.00%，链表a长度la,链表b长度lb,比如链表a长于链表b，那么先遍历b-a的长度，剩下a,b长度相同，就可以同时遍历a和b，直到找到相同的节点。

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
        struct ListNode *p,*lo,*sh;
        int la=0,lb=0,l,s;
        p=headA;
        while(p!=NULL){
            la++;
            p=p->next;
        }
        p=headB;
        while(p!=NULL){
            lb++;
            p=p->next;
        }
        if(lb>la){
            lo=headB;
            sh=headA;
            l=lb;
            s=la;
        }
        else {
            lo=headA;
            sh=headB;
            l=la;
            s=lb;
        }
        while(l>s){
            l--;
            lo=lo->next;
        }
        while(lo!=NULL&&sh!=NULL){
            if(lo==sh)return  lo;
            lo=lo->next;
            sh=sh->next;
        }
        
return NULL;
}
```