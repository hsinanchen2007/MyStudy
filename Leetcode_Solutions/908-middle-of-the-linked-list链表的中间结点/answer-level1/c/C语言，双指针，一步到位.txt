### 解题思路
![image.png](https://pic.leetcode-cn.com/6dcc309e814dc9aca4ba14b9e435828f8e32a30f351bb91f3f8afa54e8fd25df-image.png)
这道题应该没有头结点吧，头结点应该没有val值，只是next指向链表第一个结点；

然后说思路

一般双指针解法的输出，在结点为偶数个时，取到的是前一个中间结点，输出时需要取next；

如何解决这个问题呢？

经过观察可知，当快指针（代码中的p指针）后移奇数位时，快慢指针同时后移；
当快指针后移偶数位时，快指针后移，而慢指针不动；
我是设置了一个标志位，标志奇偶；
这样，输出时直接输出慢指针所指结点即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int sign=0;
    struct ListNode *p=head,*q=head;
    while(p->next!=NULL){
        if(sign==0){
            p=p->next;
            q=q->next;
            sign=1;
            continue;
        }
        if(sign==1){
            p=p->next;
            sign=0;
        }
    }
    return q;
}
```