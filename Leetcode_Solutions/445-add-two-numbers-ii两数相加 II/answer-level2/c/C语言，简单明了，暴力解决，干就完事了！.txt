### 解题思路
先逆序两链表，再依次相加，最后判断最高位是否需要进位

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){//逆序
    if(!head || !head->next)
        return head;
    struct ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(!l1->next && l1->val==0)
        return l2;
    if(!l2->next && l2->val==0)
        return l1;
    int sum;//和
    int binary = 0;//进位
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head1 = reverse(l1);
    struct ListNode* head2 = reverse(l2);
    dummy->next = NULL;
    struct ListNode* p = head1;
    struct ListNode* q = head2;
    while(p || q)
    {
        sum = 0;
        if(p && q)
        {
            sum +=  p->val + q->val + binary;
            p = p->next;
            q = q->next;
        }
        else if(p)
        {
            sum += p->val + 0 + binary;
            p = p->next;
        }
        else
        {
            sum += 0 + q->val + binary;
            q = q->next;
        }
        binary = sum / 10;
        sum %= 10;              //头插法
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val = sum;
        s->next = dummy->next;
        dummy->next = s;
    }
    if(binary)
    {
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val = binary;
        s->next = dummy->next;
        dummy->next = s;
    }
    return dummy->next;
}
```