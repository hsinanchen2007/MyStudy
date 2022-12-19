### 解题思路
此处撰写解题思路

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
        int lenA = getLinkLen(headA);
        int lenB = getLinkLen(headB);
        int diff;
        if (lenA > lenB)
        {
            diff = lenA - lenB;
            return getSameNode(headA, headB, diff);
        }       
        else
        {
            diff = lenB - lenA;
            return getSameNode(headB, headA, diff);
        }
            
    }

    ListNode * getSameNode(ListNode * fast, ListNode * slow, int diff)
    {
        for(int i = 0; i < diff; i++)
        {
            fast = fast->next;
        }
        
        while(fast != NULL)
        {
            if(fast == slow)
                return fast;
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

    int getLinkLen(ListNode * p)
    {
        int len = 0;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        return len;
    }
};
```

![Xnip2020-04-03_12-36-23.jpg](https://pic.leetcode-cn.com/bdae02be654a2a816feb5c5b2a812d2f5a46b810d99d792a9f205fd3b249f2ab-Xnip2020-04-03_12-36-23.jpg)
