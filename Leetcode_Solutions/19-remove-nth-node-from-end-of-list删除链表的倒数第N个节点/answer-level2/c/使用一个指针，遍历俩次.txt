### 解题思路
1. 第一趟遍历计算出链表长度
2. 第二趟遍历删除第L-n+1个结点

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

    int len = 0;
    struct ListNode *p = head;
    while(p!=NULL){
        len++;
        p=p->next;
    };
    if(len==n){
        return head->next;
    }
    len = len - n - 1;
    p = head;
    for(int i=0; i<len; i++){
        p = p->next;
    };
    p->next = p->next->next;
    return head;
}
```