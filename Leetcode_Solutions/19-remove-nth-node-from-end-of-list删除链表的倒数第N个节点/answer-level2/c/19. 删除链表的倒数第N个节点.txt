### 解题思路
在此提示：这个题没有不存放有效数据的头结点，为了操作方便，需要自己手动设置
每次检查一个结点，我就通过函数得到这个结点后的N个结点，看看是否后N个结点是最后一个结点
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* TheN(struct ListNode* P,int N){
    for(int i=0;i<N;i++){
        P = P->next;
    }
    return P;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* P = dummy;
    // if(TheN(P,n) == NULL){
    //     free()
    // }
    // else{
        while(TheN(P,n)->next != NULL){
            P = P->next;
        }
        struct ListNode* s = P->next;
        P->next = s->next;
        free(s);
    // }
    return dummy->next;
}
```