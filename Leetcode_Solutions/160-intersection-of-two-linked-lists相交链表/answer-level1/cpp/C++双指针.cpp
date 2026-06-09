### 解题思路
解题思路来自于官方所给第三种解法，双指针。解题思路大家可以看官方的，写得挺好。

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
    //建立两个指针用来遍历
    ListNode* ptrA{ headA };
    ListNode* ptrB{ headB };
    //假如有任何一个链表为空，必不能相交，返回NULL
    if (ptrA == NULL || ptrB == NULL)
        return NULL;
    //开始遍历
    bool A{ false }, B{ false }; //用来标记；
    while (true)
    {
        if (ptrA == NULL)  //假如到达headA的末尾
        {
            ptrA = headB;  //将指针移到headB的首元素
            A = true;
        }
        if (ptrB == NULL)  //假如到达headB的末尾
        {
            ptrB = headA;  //将指针移到headA的首元素
            B = true;
        }
        if (A && B)  //如果这两个操作都进行了，跳出循环
            break;
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    //此刻A和B所走过的路程相同，他们总的路程也相同为链表A的长度加链表B的长度
    //所以此刻他们必然经过相同步数到达链尾
    while (ptrA != NULL)  //如果到了链尾还没相遇，说明两链表不相交
    {
        if (ptrA == ptrB)  //相交返回交点
            return ptrA;
        else
        {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
    return NULL;  //不相交返回NULL
    }
};
```