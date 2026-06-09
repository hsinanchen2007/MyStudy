### 解题思路
直接返回合并两个链表

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* res =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail=res;
    while(p!=NULL&&q!=NULL){
        if(p->val<q->val){
            tail->next=p;
            p=p->next;
            tail=tail->next;
        }else{
            tail->next=q;
            q=q->next;
            tail=tail->next;
        }
    }
    tail->next=((p!=NULL)? p:q);
    return res->next;

}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
   struct ListNode *ret = NULL;
   for(int i=0;i<listsSize;i++){
       ret=mergeTwoLists(ret,lists[i]);
   } 
    return ret;
}
```