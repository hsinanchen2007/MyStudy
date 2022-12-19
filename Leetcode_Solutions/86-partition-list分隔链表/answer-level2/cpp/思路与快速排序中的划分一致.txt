### 解题思路
case1:
链表的起始部小于x
![linklist_partion3.jpg](https://pic.leetcode-cn.com/b24312c6a33b4aa3e44bbaeb47d40c204abf38d70d7514da087a351d316fb10e-linklist_partion3.jpg)

case2:起始部分大于等于x
![linklist_partion4.jpg](https://pic.leetcode-cn.com/488d7b0540ccd0c5f4bc4a3685d628080739476910dfceee4af1b59e6a57701e-linklist_partion4.jpg)

思路与快速排序中的partion的思路一致，在处理的过程中，把链表分成三部分，第一部分为已处理的小于x的部分，第二部分为已处理的不小于x的部分，以及待处理的部分
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p, *q, *r, *h = NULL, *prev, *s;

        h = NULL;//用于记录新的链表头
        p = NULL;//用于记录小于x的部分的最后一个节点
        q = head;//当前处理的节点
        prev = NULL;//当前正在处理节点的前一个节点
        r = NULL;//已处理部分的大于或等于x的第一个节点
        s = NULL;//用于记录下一个待处理的节点

        while(q)
        {
            if(q->val >= x)
            {
                //若当前的节点值大于等于x，更新prev/r/q
                if(r == NULL)
                {
                    //第一个大于等于x的节点，保存在r
                    r = q;
                }
                //prev用于保存当前正在处理的节点
                prev = q;
                //处理下一个节点
                q = q->next;
            }
            else if(q->val < x)
            {
                //若当前节点小于x
                if(h == NULL)
                {
                    //case 1第一个小于x的节点
                    p = q;//更新p
                    h = p;//记录新的链表的头节点
                    if(prev)
                    {
                        //如果第一个小于x的节点在原始链表的中间部分，需要断开连接
                        prev->next = q->next;
                    }
                    s = q->next;
                    if(r)
                    {
                        //把当前的节点链接到大于等于x的部分的第一个节点r
                        q->next = r;
                    }
                    q = s;
                }
                else if(p->next == q)
                {
                    //case 2如果当前节点是已处理部分的下一个节点，且是连续小于x的部分，更新p/q
                    p = q;
                    q = q->next;
                }
                else
                {
                    //case 3当前处理的节点的前一个节点是大于等于x
                    //需要把当前的节点链接到小于x的部分
                    s = q->next;//记录下一个待处理的部分
                    prev->next = s;//更新prev->next
                    if(p)
                    {
                        //把当前节点q链接在p/r之间
                        q->next = r;
                        p->next = q;
                        p = p->next;
                    }
                    q = s;
                }
            }  
        }

        if(h)
            head = h;
        return head;
    }
};