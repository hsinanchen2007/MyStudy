### 解题思路
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

与迭代不同的是，递归是从后向前，即从尾节点向头节点逐个翻转来实现效果的。

来自一篇博客：@Windows_Defender
https://blog.csdn.net/Windows_Defender/article/details/80114246


首先我们假定创建了一个共有5个节点的链表，像下边这样:


![1.JPG](https://pic.leetcode-cn.com/a54adfe3950c196c1597ad272283a470741bd5b5fb419d199835b9f9d148c790-1.JPG)
之后我们建立一个新的变量NewH,并同时移动H直到它们指向尾节点，此时NewH作为新的头节点，其指向固定在此位置
![image.png](https://pic.leetcode-cn.com/53fdc77ad229896c77764b7c16bfc6b36febfe89f852f6b75c4caceebf6d4b9b-image.png)
然后H指针逐层返回的时候做下图的处理，将H的指向的地址赋值给H->next->next指针，并一定注意要让H->next=NULL

说明:此处为操作的核心，实现了断链和反转其指向的功能。由递归的相关概念我们可以知道，逐级返回的一开始，head就指向前一个节点了(即'4'这个节点),而head->next->next与head的基准是不一样的！前一个在此时指的是'5'这个节点,因此其next的next，即null的next，本来是指向未开辟的(无法输出)内存，但此时我们将它改为指向前一个节点，实现了反转的效果，并在此操作后将'4'这个节点断开(即指向NULL)
![image.png](https://pic.leetcode-cn.com/567996616ba69f539c1f74c8c014d5b356a25ac48a4f47f9475f1ae56f365f93-image.png)


### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }

};
```