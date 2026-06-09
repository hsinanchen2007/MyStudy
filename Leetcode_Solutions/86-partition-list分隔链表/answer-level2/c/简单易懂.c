### 解题思路
此处撰写解题思路
一定要记得将后面一条链表的尾部指向NULL， 不然就变成环形链表， 然后就TLE了
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
    struct ListNode* head1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head2=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *t1=head1, *t2=head2, *ans;
    t1->next=NULL, t2->next=NULL;
    while(head!=NULL){
        if(head->val < x){
            t1->next=head;
            t1=t1->next;
        }
        else{
            t2->next=head;
            t2=t2->next;
        }
        // printf("%d",head->val);
        head=head->next;
    }
    t2->next=NULL;
    t1->next=head2->next;
    ans=head1->next;
    free(head1);
    free(head2);
    return ans;
}
```