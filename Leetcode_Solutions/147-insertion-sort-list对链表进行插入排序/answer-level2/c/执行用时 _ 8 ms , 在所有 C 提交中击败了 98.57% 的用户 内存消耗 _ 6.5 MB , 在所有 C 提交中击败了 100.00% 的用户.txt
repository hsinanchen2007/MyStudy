### 解题思路
链表难顶。。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL) return NULL;
    struct ListNode *L=(struct ListNode *)malloc(sizeof(struct ListNode));
    L->next=head;
    L->val=-99999;
    struct ListNode *p=head->next;             //未排序的节点们
    struct ListNode *final_sort_index=head; //排好序的最后一个节点
    struct ListNode *now_cmp=NULL;         //当前要插入的节点
    struct ListNode *insert_index=NULL;   //插入位置
    final_sort_index->next=NULL;
    while(p){
        
        insert_index=L;
        now_cmp=p;
        p=p->next;
        
        if(now_cmp->val>final_sort_index->val){
            final_sort_index->next=now_cmp;
            final_sort_index=now_cmp;
            final_sort_index->next=NULL;
            continue;
        }
        //insert_index->val<now_cmp->val&&L->next->val<now_cmp->val
        while(insert_index->next->val<now_cmp->val){
            //printf("%d ",insert_index->val);
            insert_index=insert_index->next;
        }
        //printf("888\n");
        now_cmp->next=insert_index->next;
        insert_index->next=now_cmp;
        
        
        
    }
    return L->next;
}
```