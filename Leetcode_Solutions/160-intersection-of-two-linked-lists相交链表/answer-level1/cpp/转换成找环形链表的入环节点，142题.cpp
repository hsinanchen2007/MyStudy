### 解题思路
把A链表的末尾接到B链表的开头上，然后查找环形链表的入环节点（[142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)），最后再把它断开（不知道要不要，还是断了把）

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
    ListNode *detectCycle(ListNode *head);//142题
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        
        ListNode *p = headA;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        //第一个链表末尾接到另一个链表的开头
        p->next = headB;
        ListNode *q = detectCycle(headA);
        p->next = nullptr;//再断开
        return q;
    }
};

ListNode *Solution::detectCycle(ListNode *head) { //这个是142题找环形链表的方法
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *p = head; //slow
    ListNode *q = head; //fast
    int flag = 0;
    while (p->next != NULL&&q->next != NULL)
    {
        q = q->next;
        if (flag == 0)
        {
            if (q->next != NULL)
            {
                q = q->next;
            }
            else
            {
                return NULL;
            }
        }
        
        p = p->next;
        if (p == q)
        {
            if (flag)
            {
                return p;
            }
            p = head;
            if (p == q)
            {
                return p;
            }
            flag = 1;
        }
    }
    return NULL;
}
```