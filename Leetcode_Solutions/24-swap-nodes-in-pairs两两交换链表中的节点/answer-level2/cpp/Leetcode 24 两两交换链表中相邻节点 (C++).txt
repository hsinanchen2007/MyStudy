### 解题思路
1、首先对特殊情况做一个处理
即 当只有一个节点或空节点时，直接返回head

2、此题主要在逻辑中处理好偶数个和奇数个的情况

3、e.g. 1->2->3->4->5->6->7->8->NULL
 
![IMG_6501.JPG](https://pic.leetcode-cn.com/03df9f3b099eb84a31ce6a2b947fc65ad49f0acd7b1be8884770aaa33e43798f-IMG_6501.JPG)


### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 1 2 3 4 NULL
 (1) p=1, 2->1   1->4
 (2) p=3, 4->3   3->NULL
 注意区分偶数个和奇数个，奇数个时不能漏掉最后一个元素 
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head; 

        ListNode* p = head;
        ListNode* pNewHead = head->next;
        ListNode* pn = nullptr;        
        ListNode* pnn = nullptr; 
        ListNode* pnnn = nullptr;
        while (p)
        {  
            pn = p->next;
            pnn = pn? pn->next : nullptr;
            pnnn = pnn? pnn->next : nullptr; 
            if (pn) 
            {
                pn->next = p;
            }
            
            if (pnnn)
            {
                p->next = pnnn;
            }
            // pnnn最后为NULL时，说明链表有奇数个节点；让p的next指向最后一个节点
            else
            {
                p->next = pnn; 
            }
            p = pnn;
        }

        return pNewHead;
    }
};
```