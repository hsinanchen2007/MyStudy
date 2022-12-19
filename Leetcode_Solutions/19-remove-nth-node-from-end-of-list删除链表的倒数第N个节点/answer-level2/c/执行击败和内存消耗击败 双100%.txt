### 解题思路
双指针

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
    struct ListNode *p,*q,*dev;
    dev=(struct ListNode*)malloc(sizeof(struct ListNode));
    dev->val=0;
    dev->next=head;//为了对付特殊情况，所以创建一个新的节点，该节点位于head之前
    p=dev;
    q=dev;
    int cnt=0;
    while(p){//双指针，等p->next执行n+2边的时候，q->next开始执行
        cnt++;
        p=p->next;
        if(cnt>n+1)
            q=q->next;
    }
    q->next=q->next->next;//删除倒数第n个节点
    return dev->next;//只能这样写，否则写“return head”的话有几组测试样例不能通过
}
```