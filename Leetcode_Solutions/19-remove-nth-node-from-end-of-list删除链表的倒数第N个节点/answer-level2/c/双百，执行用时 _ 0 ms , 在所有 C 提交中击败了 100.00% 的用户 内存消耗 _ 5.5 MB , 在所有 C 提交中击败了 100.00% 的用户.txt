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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len=0;
    struct ListNode* p=head;
    while(p){
        len++;
        p=p->next;
    }
    int go=len-n;
    struct ListNode*pre=NULL;
    p=head;
    while(go){
        p=p->next;
        if(pre==NULL)
            pre=head;
        else
            pre=pre->next;
        go--;
    }
    if(pre==NULL){//要删除第一个元素
        pre=p;
        p=p->next;
        free(pre);
        return p;
    }
    pre->next=p->next;
    free(p);
    return head;
}
```