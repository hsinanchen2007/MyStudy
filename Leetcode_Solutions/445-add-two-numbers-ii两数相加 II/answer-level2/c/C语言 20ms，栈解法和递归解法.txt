递归解法：
递归和栈的目的都是为了对齐。
这里递归对齐用的是两条链的长度来作比较

```
int listDepth(struct ListNode *list) {  //计算链的长度，用于后面计算对齐
    int len = 0;
    for (struct ListNode *t = list; t ; t = t->next, len++) { }
    return len;
}

int func(struct ListNode *l1, int len1, struct ListNode *l2, int len2) {  //递归算出每一位的值，存入长链l1，返回进位结果，
    if (len1 == 0) return 0;                 //计算结束
    if (len1 == len2)
        l1->val += l2->val + func(l1->next, len1 - 1, l2->next, len2 - 1);  //位置对齐
    else //if (len1 > len2)
        l1->val += func(l1->next, len1 - 1, l2, len2);     //位置不对齐，则短链用0来代替
    if (l1->val > 9) {            //计算进位
        l1->val -= 10;
        return 1;
    } else return 0;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int len1 = listDepth(l1), len2 = listDepth(l2);    //先算两条链的链长
    if (len1 < len2) {
        struct ListNode *tmp = l1; l1 = l2; l2 = tmp;      //默认l1为最长链，不是的话，我们就换一下
        int tmplen = len1; len1 = len2; len2 = tmplen;
    }
    int carry = func(l1, len1, l2, len2);   //记录最后一个进位
    if (carry) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));  //如果最高位还有进位，那个新做一个节点
        node->val = 1; node->next = l1;
        return node;
    } else return l1;   //没有进位直接返回最长链即可
}
```

栈解法：
基本思路和递归是一致的，利用栈的先进后出规则，很自然地就可以将两条链末尾对齐了。
后面就是基本的出栈操作，如果断链的栈空，就用0来代替。最后注意最高位的进位就可以了。

```
#define pop(stack, top) ((stack)[(top)--])
#define push(stack, top, val) ( (stack)[++(top)] = (val) )

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *stk1[1000], *stk2[1000], **larger, **smaller, *p1, *p2;
    int t1 = -1, t2 = -1, ltop, stop;  //栈顶标识
    for (struct ListNode *tmp = l1; tmp ; tmp = tmp->next)  //入栈
        push(stk1, t1, tmp);
    for (struct ListNode *tmp = l2; tmp ; tmp = tmp->next)  //入栈
        push(stk2, t2, tmp);
    if (t1 > t2) {  //将最长链表对应的栈设置为 larger
        larger = stk1; ltop = t1;
        smaller = stk2; stop = t2;
    } else {
        larger = stk2; ltop = t2;
        smaller = stk1; stop = t1;
    }

    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));  //设置零点
    node->val = 0;
    int carry = 0;   //进位标识
    while (ltop != -1) {
        p1 = pop(larger, ltop);
        p2 = stop == -1 ? node : pop(smaller, stop);
        p1->val += p2->val + carry;
        if (p1->val > 9) {  //将和存入较长链中
            p1->val -= 10;
            carry = 1;
        } else carry = 0;
    }
    if (carry) {  //如果还有进位，那就新加一个节点
        node->val = 1;
        node->next = p1;
        return node;
    }
    free(node);
    return p1;
}
```

