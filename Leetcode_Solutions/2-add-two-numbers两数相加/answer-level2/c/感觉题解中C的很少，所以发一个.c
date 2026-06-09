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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* result_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = result_head;

    int x;
    int y;
    int sum;
    int carry = 0;

    while(p!=NULL || q!=NULL || carry==1){
        x = (p!=NULL)?p->val:0;
        y = (q!=NULL)?q->val:0;
        sum = x+y+carry;
        carry = sum/10;
        sum = sum%10;

        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val = sum;
        cur = cur->next;

        if(p!=NULL){
            p = p->next;
        }
        if(q!=NULL){
            q = q->next;
        }

    }
    cur->next = NULL;

    return result_head->next;

}
```