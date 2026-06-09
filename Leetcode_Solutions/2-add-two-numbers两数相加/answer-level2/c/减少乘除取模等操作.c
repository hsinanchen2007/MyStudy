### 解题思路
每位数和进位相加，最后如果进位不为0就再补一位。把/和%用x>9?x-10:x;和x>9?1:0;代替效率会提高很多

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1->val==0 && !l1->next) return l2;
    if (l2->val==0 && !l2->next) return l1;
    int carry=0;
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->next=NULL;
    struct ListNode* rear=p;
    while (l1 && l2) {
        struct ListNode* tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
        int x=l1->val+l2->val+carry;
        tmp->val=x>9?x-10:x;
        carry=x>9?1:0;
        tmp->next=NULL;
        rear->next=tmp;
        rear=rear->next;
        l1=l1->next;
        l2=l2->next;
    }
    while (l1) {
        struct ListNode* tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
        int x=l1->val+carry;
        tmp->val=x>9?x-10:x;
        carry=x>9?1:0;
        tmp->next=NULL;
        rear->next=tmp;
        rear=rear->next;
        l1=l1->next;
    }
    while (l2) {
        struct ListNode* tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
        int x=l2->val+carry;
        tmp->val=x>9?x-10:x;
        carry=x>9?1:0;
        tmp->next=NULL;
        rear->next=tmp;
        rear=rear->next;
        l2=l2->next;
    }
    if (carry) {
        struct ListNode* tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val=carry;
        tmp->next=NULL;
        rear->next=tmp;
        rear=rear->next;
    }
    rear=p;
    p=p->next;
    free(rear);
    return p;
}
```