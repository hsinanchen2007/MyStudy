### 解题思路
这个是参考了官方题解的写法，比第一次过的代码简洁太多了，之前的代码写得太啰嗦了，拆成好几部分，先把两个数长度一样的相加，然后再处理长度超出的部分，最后再处理最后一位是否有进位。

现在的做法是把前面的两步合在一起，大大减少了很多冗余代码，而且速度也提升了。

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
            struct ListNode *a, *t, *ans = NULL;
    int v, v1, v2, carry = 0;

    while (l1 || l2) {
        v1 = l1 ? l1->val : 0;
        v2 = l2 ? l2->val : 0;
        t = (struct ListNode *) malloc(sizeof(struct ListNode));
        v = v1 + v2 + carry;
        t->val = v%10;
        carry = v/10;
        t->next = NULL;

        if (!ans) {
            ans = a = t;
        } else {
            a = a->next = t;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry != 0) {
        t = (struct ListNode *) malloc(sizeof(struct ListNode));
        t->val = carry;
        t->next = NULL;
        a->next = t;
    }
    return ans;
}
```