### 解题思路
指定两个链表，before和after（哑Listnode）。before中存的是小于x的，after中存的是大于等于x的。之后将before的最后一个元素的next连接到after的next的第一个元素。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if(!head)
    {
        return head;
    }
    struct ListNode *before = (struct ListNode*)malloc(sizeof(struct ListNode));
    before->next = NULL;
    struct ListNode *after = (struct ListNode*)malloc(sizeof(struct ListNode));
    after->next=NULL;
    struct ListNode *tmp_before = before;
    struct ListNode *tmp_after = after;
    struct ListNode*res = NULL;
    while(head)
    {
        if(head->val<x)
        {
            tmp_before->next=head;
            tmp_before=tmp_before->next;
        }
        else
        {
            tmp_after->next=head;
            tmp_after = tmp_after->next;
        }
        head=head->next;
    }
    tmp_before->next = after->next;
    tmp_after->next=NULL;
    res = before->next;
    free(after);
    free(before);
    return res;
}
```