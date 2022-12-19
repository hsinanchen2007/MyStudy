这也是剑指上的一道题，我采用的是剑指上的第三个方法。
思路：
遍历得到两个链表的长度，求长度差diff；
两个指针分别指向两个链表的头结点，让更长的那个链表的指针先走diff步后，两个指针在同时移动，遇到的第一个相同的节点就是他们的公共节点。
代码虽然有点长，但是简单

```
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *CommomNode = nullptr;
    if(headA != nullptr && headB != nullptr)
    {
        int countA = 0;
        int countB = 0;
        ListNode *pNodeA = headA;
        ListNode *pNodeB = headB;
        while(pNodeA != nullptr)
        {
            countA++;
            pNodeA = pNodeA->next;
        }
        while(pNodeB != nullptr)
        {
            countB++;
            pNodeB = pNodeB->next;
        }
        //长的链表先走
        pNodeA = headA;
        pNodeB = headB;
        int diff = abs(countA - countB);
        if(countA > countB)
        {
            for(int i = 0;i < diff;i++)
            {
                pNodeA = pNodeA->next;
            }
        }
        else if(countA < countB)
        {
            for(int i = 0;i < diff;i++)
            {
                pNodeB = pNodeB->next;
            }
        }

        while(pNodeA!= nullptr && pNodeB != nullptr)
        {
            if(pNodeA == pNodeB)
            {
                CommomNode = pNodeA;
                break;
            }
            pNodeA = pNodeA->next;
            pNodeB = pNodeB->next;
        }
    }
    return CommomNode;
}
```
