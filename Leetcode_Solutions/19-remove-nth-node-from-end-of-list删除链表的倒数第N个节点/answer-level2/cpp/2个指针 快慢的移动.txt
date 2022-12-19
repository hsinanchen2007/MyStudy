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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)
        {
            return head;
        }
        if(n<=0)
        {
            return head;
        }
        ListNode* pFast=head;
        ListNode* pSlow=nullptr;
        int nNum=0;//pFast已经走过的节点数量
        while(pFast->next!=nullptr)
        {
            pFast=pFast->next;
            if(++nNum>n)
            {
                pSlow=pSlow->next;
                continue;
            }
            if(nNum==n)
            {
                pSlow=head;
            }
        }
        if(pSlow==nullptr)
        {
            return head->next;
        }
        pSlow->next=pSlow->next->next;
        return head;
    }
};
```
执行时间很飘，从4-12ms 都有