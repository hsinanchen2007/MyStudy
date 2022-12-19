### 解题思路
提供一个链表的尾端插入函数insert，使用尾插函数更简便，但是效率低下，因为每一次调用函数都要从头遍历节点完成新节点的插入。
这里直接在addTwoNumbers中完成插入新节点的操作，由于这样避免了调用insert函数的弊端，所以时间效率更高一点（10%-30%左右）
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//尾端插入函数，该解法不会调用，仅供参考（可以不看）
// void insert(const struct ListNode* head,const int val)
// {
//     struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
//     q->val = val;
//     q->next = NULL;
//     struct ListNode* p = head;
//     while (p->next) {
//         p = p->next;
//     }
//     p->next = q;
// }

// void insert(struct ListNode* head,int obj){
//     struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
//     t->val = obj;
//     t->next = NULL;
//     struct ListNode* t1 = head;
//     while(t1->next)
//         t1 = t1->next;
//     t1->next = t;
// }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0,num;
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = l3;
    l3->next = NULL;
    while(l1 && l2){
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->next = NULL;
        num = l1->val + l2->val + carry;
        if(num > 9)
            carry = 1;
        else    
            carry = 0;
        t->val = num%10;
        l3->next = t;
        l1 = l1->next;
        l2 = l2->next;
        l3 = l3->next;
    } 
    if(l1){
        while(l1){
            struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
            t->next = NULL;
            num = l1->val + carry;
            if(num > 9)   carry = 1;
            else    carry = 0;
            t->val = num%10;
            l3->next = t;
            l1 = l1->next;
            l3 = l3->next;
        }
    }
    else if(l2){
        while(l2){
            struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
            t->next = NULL;
            num = l2->val + carry;
            if(num > 9)   carry = 1;
            else    carry = 0;
            t->val = num%10;
            l3->next = t;
            l2 = l2->next;
            l3 = l3->next;
        }
    }
    if(carry){
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->next = NULL;
        t->val = 1;
        l3->next = t;
    }
    return head->next;
}
```