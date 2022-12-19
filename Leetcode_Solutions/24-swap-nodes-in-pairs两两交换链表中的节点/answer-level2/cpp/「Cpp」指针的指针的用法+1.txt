### 解题思路

如果使用Java，Python这些不提供指针的编程语言，通常需要声明一个哑节点。

在「C语言指针」里提到过如何用指针的指针来处理第一个节点的赋值和删除，然而我只是觉得牛逼而已，并不知道如何用。直到我看了这篇 https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019/7-8-lines-C%2B%2B-Python-Ruby 

Java和Python可能会通过如下操作搞一个哨兵节点，在第一节点前加一个节点。

```cpp
ListNode dummy = new ListNode(-1);
dummy->next = head;
```

但是C/C++的指针让我们用`ListNode **pp = &head`的声明方式，搞了一个指向head地址的指针。

在第一个循环中 ` while ( (a = *pp) && (b = a->next))`，a就是head(因为`pp`是`&head`, 所以 `*pp` 是 `*&head`, 也就是head`)， b也就是a->next

然后`a->next = b->next ; b->next = a` ，也就是原来的 `->a->b->c` ,现在变成了 `b->a->c`.

![image.png](https://pic.leetcode-cn.com/b0da93e12835541affd26f6e92e05c1ec378b7b01957106ba94c16b0a9397203-image.png)

这一波操作之后，b的前继节点没了。这就到了最难以理解`*pp=b; pp=&(a->next)`。

为了理解他们，让我们在上一张图中加上他们

![image.png](https://pic.leetcode-cn.com/2d908fb9584364c66300111d1e9463cfde0f57bcad3c80ade12c01b174a6f327-image.png)

我们的任务是将原来指向a的指针指向b，

我们知道pp是指向指针的指针，那么`*pp`就是那个被指向的指针，也就是上图的红线，那么`*pp=b`也就是将原本指向a的指针指向了b。

接着`pp = &(a->next)`就可是把pp指向**a的next指针**。因为`a->next`和head一样，都是指向下一个节点的指针。

![image.png](https://pic.leetcode-cn.com/8c597da9de1750ec547532f4ecf8b6d4048b9e6da23c3d1238ba17c5b43214ba-image.png)

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ( (a = *pp) && (b = a->next)){
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;

    }
};
```

实在是秒啊！给写出这个代码的大神献出膝盖

无缝切换到C语言

```c
struct ListNode* swapPairs(struct ListNode* head){
    
    struct ListNode **pp = &head, *a, *b;

    while( (a = *pp) && ( b = a->next )){
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;

}
```

运行时间0ms，100.00%达成

![image.png](https://pic.leetcode-cn.com/fea615ab515cbb5c28823213756bd0d9e7cfc5661cb81243be95b8714794382b-image.png)
