### 解题思路
idea:单次循环
* 实质上只需遍历至右端点`n`
* `pre`指向左边节点的前一节点，主要是为了翻转后和其它节点的连接；
* 两个连续的指针`pleft,pright`实现`m-n`链表的翻转，从链表第m个节点开始翻转。
    - 翻转操作类似于swap操作，需要引入中间变量
    - 翻转后还要对链表进行连接
 * 最后还要判断是否是从表头开始翻转，是的话将翻转节点的最右端赋给`head`.



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
/*
** 单次循环
*/
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre=new ListNode(-1);
        pre->next=head;
        for(int i=1;i<m;i++)
        {
            pre=pre->next;
        }
        ListNode *pleft=pre->next,*pright=pre->next->next; // pleft 记录m位置,pright为下一位置
        for(int i=m;i<n;i++) //翻转
        {
            ListNode *ptmp=pright->next;
            pright->next=pleft;
            pleft=pright;
            pright=ptmp;
        }
        if(pre->next==head) head=pleft; // 如果从首个位置翻转需要更换链表头
        // 翻转后队头和队尾与其他节点连接
        pre->next->next=pright;
        pre->next=pleft;
        return head;
    }
};
```