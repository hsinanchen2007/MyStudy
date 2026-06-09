### 解题思路
此处撰写解题思路
基本采用栈的思想，不过时间有点慢。。。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int pos = 0;
        vector<ListNode*> nodeStack(k, nullptr);
        if(k == 1)
            return head;

        ListNode* newHead = nullptr;
        ListNode* q = nullptr;
        ListNode* r = head;
        ListNode* p = head;
        while(r != nullptr)
        {
            r = r->next;
            pos ++;
            if(pos == k)
            {
                ListNode* s = p;
                for(int i = 0; i < k; i++)
                {
                    nodeStack[i] = s;
                    s = s->next;
                }
                for(int i = k - 1; i >= 0; i--)
                {
                    if(newHead == nullptr)
                    {
                        newHead = nodeStack[i];
                        q = newHead;
                    }
                    else
                    {
                        q->next = nodeStack[i];
                        q = q->next;
                    }
                }
                pos = 0;
                p = r;
            }
        }

        while(p != nullptr)
        {
            q->next = p;
            p = p->next;
            q = q->next;
        }
        q->next = nullptr;
        return newHead;
    }
};
```