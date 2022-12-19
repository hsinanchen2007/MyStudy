### 解题思路
此处撰写解题思路
![2019-12-28_233523.png](https://pic.leetcode-cn.com/0be74ddf3d347d901524b5c2139000046ce897c2d91abc25296d86cb473e4aab-2019-12-28_233523.png)
维护两个链表，最后连接这两个链表。
通过赋值，尽量把while大循环的判断语句省略掉，这样可以大大减少运行时间。
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
        if(!head||!head->next)
            return head;
        ListNode *pt1=new ListNode(0);
        ListNode *pt2=new ListNode(0);
        ListNode *h=head,*p1=h,*p2=NULL,*pre=pt1;
        ListNode *t1=pt1,*t2=pt2;
        //p2=NULL;pre=pt1;//赋初值，为后面不用判断p2与p1的关系做准备
        while(h)
        {
            while(p1 && p1->val<x)
            {
                p2=h;
                pre=p1;
                p1=p1->next;
            }
            t1->next=p2;
            t1=pre;

            p2=NULL;pre=t2;h=p1;//重新赋值，不用判断p2与p1的关系
            while(p1 && p1->val>=x)
            {
                p2=h;
                pre=p1;
                p1=p1->next;
            }
            t2->next=p2;
            t2=pre;

            h=p1;p2=NULL;pre=t1;//重新赋值，不用判断p2与p1的关系
        }
        t1->next=pt2->next;
        return pt1->next;
    }
};
```