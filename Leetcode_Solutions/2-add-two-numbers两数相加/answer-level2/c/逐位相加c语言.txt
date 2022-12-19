### 解题思路
既然链表的每一个节点都是一位数字，那么我们要计算两个数字之和只需从表头开始逐位相加即可，思想很简单，主要是要处理每一位数相加产生的进位。我们将进位carry初始化为0，因为刚开始没有进位，每次将相对应的两位数字以及进位相加，得到三个数字之和，然后分离出和的十位和个位，十位数字即是进位数字，个位数字即是当前节点的val。
如果两条链表长度不一，那么最后将剩下的长链表的多余部分单独处理，要注意的是当长链表每个节点也遍历完了之后不一定就结束了，因为可能最后一位数字有进位，比如1+99的情况。

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
    struct ListNode* p = l1,* q = l2,*res,*t,*r;
    res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->next = NULL;
    r = res;
    int temp,carry = 0;
    temp = p->val + q->val + carry;
    carry = temp/10;
    res->val = temp%10;
    p = p->next;
    q = q->next;
    while(p != NULL && q != NULL){
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp = p->val + q->val + carry;
        carry = temp/10;
        t->val = temp%10;
        t->next = NULL;
        r->next = t;
        r = t;
        p = p->next;
        q = q->next;
    }
    if(p != NULL){
        r->next = p;
        while(carry == 1 && p != NULL){
        temp = p->val + carry;
        carry = temp/10;
        p->val = temp%10;
        r = p;
        p = p->next;
        }
    }
    if(p == NULL && carry == 1){
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = carry;
        t->next = NULL;
        r->next = t;
    }
    if(q != NULL){
        r->next = q;
        while(carry == 1 && q != NULL){
        temp = q->val + carry;
        carry = temp/10;
        q->val = temp%10;
        r = q;
        q = q->next;
        }
    }
    if(q == NULL && carry == 1){
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = carry;
        t->next = NULL;
        r->next = t;
    }
    return res;
}
```