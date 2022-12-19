### 解题思路
有几个边界条件：

1. 两个数的长度相等，并且有进位
2. 两个数的长度不相等，并且有额外的进位

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
        int extra = 0;
    int v = 0;
    struct ListNode* a , *t, *l, *ans;
    a = ans = NULL;

    while (l1 && l2) {
        t = (struct ListNode *) malloc(sizeof(struct ListNode));
        v = l1->val+l2->val+extra;
        
        t->val = v%10;
        t->next = NULL;
        if (ans == NULL) {
            ans = a = t;
        } else {
            a->next = t;
            a = a->next;
        }
        extra = v/10;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (!l1 && !l2) {
        if (extra != 0) {
            t = (struct ListNode *) malloc(sizeof(struct ListNode));
            t->val = extra;
            t->next = NULL;
            a->next = t;
        }
        return ans;
    } else {
        l = l1 ? l1 : l2;
        while (l) {
            t = (struct ListNode *) malloc(sizeof(struct ListNode));
            v = l->val + extra;
            t->val = v%10;
            t->next = NULL;
            extra = v/10;
            a->next = t;
            a = a->next;
            l = l->next;
        }
        if (extra != 0) {
            t = (struct ListNode *) malloc(sizeof(struct ListNode));
            t->val = extra;
            t->next = NULL;
            a->next = t;
        }

    }

    return ans;
}
```