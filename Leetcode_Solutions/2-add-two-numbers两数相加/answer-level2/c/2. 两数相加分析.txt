## [题目描述](https://leetcode-cn.com/problems/add-two-numbers/)
给出两个**非空**的链表用来表示两个非负的整数。其中，它们各自的位数是按照**逆序**的方式存储的，并且它们的每个节点只能存储**一位**数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字**0**之外，这两个数都不会以**0**开头
**示例：**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

## 题目题解
这道题的思路还是比较简单的，简单的说一下
实际上，这就是单向链表的遍历，只不过需要注意不同行为的条件即可。注意需要考虑的就是什么时候进位，以及如何处理进位。

为了节约内存，我们不妨规定返回的始终是`l1`
那么，当我们考虑种种条件时，我们永远从最简单的开始考虑起
### 1. 如果`l1->next && l2->next`
之所以考虑这种情况，是因为这种情况下的进位完全不需要过多的考虑。就是最普通的带进位的加法。所以这种情况下的处理方式如下所示
```
l1->val += l2->val;
if(l1->val > 9){
    l1->val %= 10;
    l1->next->val += 1;
}
```
### 2. 如果`!l2->next`
如果第一种情况情况不符合的话，则要么`!l1->next`，要么`!l2->next`。但是由于我们设定的是返回的是`l1`，则我们从简单的情况来考虑，也就是`!l2->next`。此时也很简单，由于没有了`l2`的参与，问题仅仅和`l1`相关了。而由于有上一位的进位，如果此时`l1->val > 9`,也就是需要进位，如果`!l1->next`，那么新申请一个结构即可；否则的话，直接进位即可。所以这种情况的代码如下所示
```
while(l1->val > 9 && l1->next){
    l1->val %= 10;
    l1->next->val += 1;
    l1 = l1->next;
}
    
if(l1->val > 9){
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val %= 10;

    l1 = l1->next;
    l1->val = 1;
    l1->next = 0;
}
```
### 3. 如果`!l1->next`
正如2.中分析到的，如果第一种情况情况不符合的话，则要么`!l1->next`，要么`!l2->next`。实际上，虽然这是两种情况，但是可以转换为一种情况。对于`!l1->next`的情况，只需要让处理完当前位后，让`l1->next = l2->next`，那么实际上就又转换为了2.中的情况。那么代码如下
```
l1->val += l2->val;

if(l2->next){
    l1->next = l2->next;
}
```

当然，虽然分析的顺序是这样的，但明显的，最终的代码顺序并不是这样，我们首先不停地循环情况1，直到情况1终止，然后首先执行情况3，这样子，无论如何，最终都落到了情况2中，在循环执行情况2即可。最终的代码如下
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * return the l1
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res = l1;
    while(l1->next && l2->next){
        l1->val += l2->val;
        if(l1->val > 9){
            l1->val %= 10;
            l1->next->val += 1;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    l1->val += l2->val;

    if(l2->next){
        l1->next = l2->next;
    }

    
    while(l1->val > 9 && l1->next){
        l1->val %= 10;
        l1->next->val += 1;
        l1 = l1->next;
    }
    
    if(l1->val > 9){
        l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l1->val %= 10;

        l1 = l1->next;
        l1->val = 1;
        l1->next = 0;
    }
    return res;
}
```
