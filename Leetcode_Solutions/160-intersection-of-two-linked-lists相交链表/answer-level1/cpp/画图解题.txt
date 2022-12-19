### 解题思路
一、 去掉A和B链表中“不对齐”的部分，截掉较长的链表中前面多余的节点。在这里依据很简单A+B == B+A,即A走完A的路，再走B的路与B走完B的路，再走A的路，两个过程总路程是一样的，若相交，则A和B最后一段路程必定是一起走的。具体怎么截取呢？A在A，B在B，A或B其中一个走到头，去对方的起点；再继续走，A或B其中一个再走到头，也去对方的起点，这时两人剩余的距离是一样的
![image.png](https://pic.leetcode-cn.com/f34e777e7702312b139b21d0b7dc1fff1152dfc96fbbab998cc8ff00818eca64-image.png)
比如这图：红色是A，绿色是B，同步幅开始走。
**1.**  A从A出发，B从B出发；
**2.**  B先走完B的路，然后B去A的起点；
**3.**  继续走，A又走完A的路，然后A去B的起点；
**4.**  此时A和B位于画圈的位置，剩余路程是一样的，到这里S代表的路程其实就是我们要截取掉的部分；
**5.**  然后就可以同步遍历，直接判断节点是否相同。
***注意：截取完，位于画圈处A和B的位置并不一定是相交的位置，只是方便我们同步遍历的起点位置。***
二、 分别遍历两个链表，找到相同节点时返回该节点，否则返回NULL
***注意：先判断A和B表头是否为NULL，有一个为NULL就直接返回NULL***

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        for (int i=0; i<2; i++)
        {
            while (tempA && tempB)
            {
                tempA = tempA->next;
                tempB = tempB->next;
            }
            if (tempA == NULL && tempB == NULL)
                {
                    tempA = headA;
                    tempB = headB;
                }
            else if (tempB == NULL)
                tempB = headA;
            else
                tempA = headB;
        }
        while (tempA)
        {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
```