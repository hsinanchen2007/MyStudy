### 解题思路
用链表求和本质就是在模拟手工计算加法的过程。只要注意进位和个位对齐就可以了。
这个题的好处在于，和数的存储方式是倒序的，因此我们就不需要考虑个位对齐问题了，
直接从头开始遍历就可以了。
由于，和数链表是倒序的，所以相加后的结果，本身就是倒序的，因此求和链表采用尾插法就可以实现了。

拓展一下：头插法和尾插法。顾名思义，头插法就是结点每次都从头部插入，尾插法则结点每次从尾部插入。
         这两个方法刚好就可以用来正序存储链表和倒序存储链表，是值得掌握的。

问一个题外话，这个执行时间，为什么提交和本地不一样？同一个程序，提交两次的执行时间也不一样？
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode LNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    LNode *s, *r, *C;
    int flag = 0;

    C = (LNode*)malloc(sizeof(LNode));
    C ->next = NULL;
    r = C;

    while (l1 != NULL && l2 != NULL)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->val = l1->val + l2->val + flag;
        flag = 0;
        if (s->val > 9)
        {
            s->val = s->val - 10;
            flag = 1;
        }
        r->next = s;        //保证相加后结果倒序，所以求和链表采用尾插法
        r = s;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->val = l1->val + flag;
        flag = 0;
        if (s->val > 9)
        {
            s->val = s->val - 10;
            flag = 1;
        }
        r->next = s;
        r = s;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->val = l2->val + flag;
        flag = 0;
        if (s->val > 9)
        {
            s->val = s->val - 10;
            flag = 1;
        }
        r->next = s;
        r = s;
        l2 = l2->next;
    }
    if (flag)
    {
        flag = 0;
        s = (LNode*)malloc(sizeof(LNode));
        s->val = 1;
        r->next = s;
        r = s;
    }
    r->next = NULL;

    return C->next;
}

```