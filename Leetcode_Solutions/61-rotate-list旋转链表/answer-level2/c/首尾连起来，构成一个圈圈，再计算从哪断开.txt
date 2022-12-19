### 解题思路
此处撰写解题思路

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
    if(head==NULL)
        return NULL;
    struct ListNode* pre=NULL;
    struct ListNode* p=head;
    int len=0;
    while(p){
        len++;
        if(pre==NULL)
            pre=head;
        else
            pre=pre->next;
        p=p->next;
    }
    pre->next=head;
    p=head;
    int step=len-k%len;
    while(step){
        pre=p;
        p=p->next;
        step--;
    }
    pre->next=NULL;
    return p;
}
```