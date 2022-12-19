
1. 基本方法（2次遍历）：先遍历整个链表，求出长度len，要删除倒数第n个节点，也就是顺数N = len-n+1个节点，于是再一次遍历即可。（代码略，不符合题目要求）
2. 一次遍历方法：（请自己画图验证）
  - 设置一个哑节点，用来保证可以删除头节点；
  - 设置两个节点p,q，让两个节点之间的距离为n, (假设p不动，q往后移动）；
  - 当q->next不为空时，p,q两个节点一起往后移动，直到q->next为空，则停止；
  - 将p->next的节点进行删除，就是题目的答案。

![12.png](https://pic.leetcode-cn.com/f482073cd651ccfc751e790f759ec266bbdb8c99ab569621bbf613e8ea646365-12.png)


```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);  //哑节点
        if(!head)  return head;
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for(int i=0; i<n;i++)
        {
        q=q->next;
        }
        while(q->next)
        {
           p= p->next;
           q= q->next;
        }
        p->next = p->next->next;  //删除p->next的节点
   
        ListNode* res = dummy->next;
        delete dummy;   //删除哑节点
        return res;

    }
};
```
