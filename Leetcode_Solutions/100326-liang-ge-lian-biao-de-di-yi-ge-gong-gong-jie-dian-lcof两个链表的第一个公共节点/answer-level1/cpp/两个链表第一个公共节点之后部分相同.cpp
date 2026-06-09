### 解题思路
若A链表与B链表等长，则利用两个指针同时向后遍历两个链表，若对应节点相等则为第一个公共节点；
若A链表与B链表不等，则较长的链表空转至与短链表等长位置，开始采用等长遍历的方法。
时间复杂度o(n)

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
    int listLength(ListNode *head)
    {
        int n=0;
        ListNode* p=head;
        while(p)
        {
            n++;
            p=p->next;
        }
        return n;
    } 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alength=listLength(headA);
        int blength=listLength(headB);
        if(alength>blength)
        {
            swap(headA,headB);
            swap(alength,blength);
        }
        for(int i=0;i<blength-alength;i++)
        {
            headB=headB->next;
        }
        while(headA)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
```