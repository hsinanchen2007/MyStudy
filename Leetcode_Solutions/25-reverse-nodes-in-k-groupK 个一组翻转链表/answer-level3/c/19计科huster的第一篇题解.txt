### 解题思路
大一计科新人，目前仅掌握C语言这一门编程语言。近来在自学《数据结构与算法分析C语言描述》。算是巩固刚刚上手的编程语言并且提前学习大二课程吧。
言归正传，两天前看到一道数据结构题：从尾部k元一组反转单链表。
单链表没法从后向前处理，因此一个自然的想法就是先将链表整体逆序之后，从前向后进行k元反转。（这样就得到了这一道题）最后再次将链表整体反转就完成了从后向前的k元反转。
观察特点：每k个节点为一个反转小组，反转后这一组最后一个节点的后继节点作为下一个k元小组的头节点进行反转。
显然，通过递归描述可以很清晰地反应出处理过程。（由于初涉数据结构类问题，不是特别清楚常数额外空间的含义，是否说明不能递归呢？还请各位大佬解惑）
简单来说每组递归结束之后，要开启下一个递归小组，并将下一个元组反转之后的“头节点”作为当前元组的“尾节点”的后继节点。而递归边界就是不足以满足k元小组的情况，这时就可以直接返回当前小组的“头节点”作为上一个小组的后继。

我最终给出的处理是递归包装下的迭代过程，细节在代码的注释中有所体现。
最后给出思考的图示（手写在稿纸上，不算美观但个人认为较为清晰地反映了思路吧）。
![IMG_20200213_211106.jpg](https://pic.leetcode-cn.com/168f3ad4d90d399272d87d6d8ca780b2d73c5e503ad5c21382c8dc7314a493d4-IMG_20200213_211106.jpg)

![IMG_20200213_212224.jpg](https://pic.leetcode-cn.com/d6565019caaeb739e23a978f5d8a71e233a523eaa7029cb54c4c08ae6a10abfb-IMG_20200213_212224.jpg)

![)`CE04OC\]DU\]9@QQ7{FDH41.png](https://pic.leetcode-cn.com/7d21c6c1185756bd03a8b1bd978c796cb844287813402688ed27364fe645b7ef-\)%60CE04OC%5DDU%5D9@QQ7%7BFDH41.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *headp = head, *temp, *head0;
    head0 = head;
    int i;
    for(temp = headp, i = 0; temp && i < k; i++, temp = temp->next)
    ;                               //作用是确定出一个完整的反转小组
    if(!temp && i < k)
        return headp;               //若不足k元,直接返回原本头节点
    struct ListNode *cur, *newhead = temp;
    while(headp != temp)
    {
        cur = headp;
        headp = headp->next;
        cur->next = newhead;
        newhead = cur;
    }                               //“伪造”的递归核心,由迭代实现每个小组的反转
    head0->next = reverseKGroup(temp, k);
    return newhead;                 //返回该小组的“头节点”作为上一小组“尾节点”后继
}
```