### 解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    typedef struct ListNode List;
    int carry = 0;
    int sum, val_1, val_2 = 0;
    List *result = (List*)malloc(sizeof(List));
    List *p = result;
    List *q = NULL;

    while(l1 || l2)
    {
        val_1 = l1 ? l1->val : 0;
        val_2 = l2 ? l2->val : 0;
        
        sum = val_1 + val_2 + carry;
        carry = sum / 10;
        sum -= 10 * carry;

        p->val = sum;

        l1 = l1 && l1->next ? l1->next : NULL;
        l2 = l2 && l2->next ? l2->next : NULL;

        p->next = (List*)malloc(sizeof(List));
        q = p;
        p = p->next;

    }

    if(carry > 0)
    {
        p->val = 1;
        p->next = NULL;
    }
    else
    {
        q->next = NULL;
    }
    

    return result;
}
```