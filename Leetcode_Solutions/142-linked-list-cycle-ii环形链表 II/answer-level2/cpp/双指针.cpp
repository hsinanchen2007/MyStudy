### 解题思路
双指针

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
    //环形链表的入口节点
    //首先找到环中的一个点，然后判断这个环路的长度，最后设置快慢指针，快指针首先向前走环路长度个节点，接着与慢指针同时走，相遇的时候就是入口节点
    ListNode* find_cycle(ListNode* head)
    {
        //通过快慢指针进行操作
        ListNode* pFast = head->next;
        ListNode* pSlow = head;
        while(pFast!=nullptr&&pSlow!=nullptr&&pFast!=pSlow)
        {
            ListNode* next = pFast->next;
            if(next==nullptr) return nullptr;
            if(next==pSlow) return next;
            pFast = next->next;
            if(pFast==nullptr) return nullptr;
            if(pFast==pSlow) return pFast;
            pSlow = pSlow->next;
        }
        if(pFast!=nullptr&&pSlow!=nullptr&&pSlow==pFast) return pFast;
        return nullptr;
    }
    int deep(ListNode* cycle)
    {
        int k = 0;
        ListNode* pNode = cycle->next;
        while(pNode!=cycle)
        {
            k++;
            pNode = pNode->next;
        }
        return k+1;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        ListNode* cycle = find_cycle(head);
        if(cycle==nullptr) return nullptr;
        //寻找环路长度
        int len = deep(cycle);
        //设置快慢指针
        ListNode* pFast = head;
        ListNode* pSlow = head;
        while(len--)
        {
            pFast = pFast->next;
        }
        while(pFast!=pSlow)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};
```