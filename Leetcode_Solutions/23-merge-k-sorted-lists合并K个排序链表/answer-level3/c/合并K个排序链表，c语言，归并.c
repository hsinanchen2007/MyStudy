### 解题思路
此处撰写解题思路

### 代码

```c
//思路：类似于外排，12、34、56...两两归并，然后把归并好的在两两归并。时间复杂度O(Nlogk)，N是结点总个数，k是链表个数。空间O(1)。
//还有多路平衡归并和败者树、最佳归并树之类的思想以后再学.....
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
   if(listsSize == 0){
       return NULL;
    }
    for(int i=1;i<listsSize;i*=2){
        for(int j=0;j+i<listsSize;j=j+i+i){
            struct ListNode *p=lists[j],*q=lists[j+i];
            struct ListNode *r = (struct ListNode*)malloc(sizeof(struct ListNode)); //头结点
            lists[j] = r;
            while(p && q){
                if(p->val < q->val){
                    r->next = p;
                    p = p->next;
                }else{
                    r->next = q;
                    q = q->next;
                }
                r = r->next;
            }
            r->next = (q?q:p);
            r = lists[j];
            lists[j] = lists[j]->next;
            free(r);
        }
    }
    return lists[0];
}
```