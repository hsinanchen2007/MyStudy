### 解题思路
正着解；第一次遍历算长度，第二次删除。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //设置一个dummy头节点。
    struct ListNode*H =(struct ListNode*)malloc(sizeof(struct ListNode));
    H->next = head;
    //两个指针跟随用于删除
    struct ListNode*p = H->next,*pre = H;
    int cnt = 1;
    int i = 1;
    while(p){
        p = p->next;
        cnt++;//计算length
    }
        p = H->next;//把p拉回去
    while(i<(cnt-n) ){
        pre = p;
        p  = p->next;
        i++;
    }//循环结束，pre位于要删除节点的前驱，p在删除位置
    pre->next = p->next;
    free(p);
    return H->next;
}
```