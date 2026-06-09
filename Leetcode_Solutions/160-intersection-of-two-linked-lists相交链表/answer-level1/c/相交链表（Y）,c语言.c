### 解题思路
若AB两个链表有相交结点，这个结点到两个链表的表尾长度是一样的，如同Y字母。将两链表表尾位置对齐，然后从短的那个链表表头的位置开始遍历。
![1111.png](https://pic.leetcode-cn.com/63f4874dac1036799c9f5bece8fdacab7f5403a59c4303a3740f1113bcf12d47-1111.png)
官方题解三：遍历A+B和B+A的方法原理相同

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
    struct ListNode *p=headA,*q=headB;
    int conutA=0,countB=0;
    while(p){
        conutA++;
        p = p->next;
    }
    while(q){
        countB++;
        q = q->next;
    }
    p = headA;
    q = headB;
    if(conutA>countB){
        for(int i=0;i<conutA-countB;i++){
            p = p->next;
        }
    }else{
        for(int i=0;i<countB-conutA;i++){
            q = q->next;
        }
    }
    while(p){
        if(p == q){
            return p;
        }
        p = p->next;
        q = q->next;
    
    }
    return NULL;
}
```