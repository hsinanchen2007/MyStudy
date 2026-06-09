### 解题思路
观察可知，其本质就是找到断点，将链表分成两段，后一段的尾部链接前一段的头部。
特殊情况单独考虑

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k==0||head==NULL||head->next==NULL){//特殊情况，k=0，链表空，链表只有一个元素
        return head;
    }
    struct ListNode*p=head;int nodenum=0;int realk=0;
    struct ListNode*a=head;struct ListNode*b;
    while(p){
        nodenum++;
        p=p->next;
    }
    if(k<=nodenum){//k是从右往左，realk是从左往右，将k变成realk
        realk=nodenum-k;
    }else{
        realk=nodenum-k%nodenum;
    }
    if(realk%nodenum==0){//特殊情况，不用旋转
        return head;
    }
    for(int i=0;i<realk-1;i++){
        a=a->next;
    }
    b=a->next;
    a->next=NULL;
    struct ListNode*t=b;
    while(t->next){
        t=t->next;
    }
    t->next=head;
    return b;
}
```