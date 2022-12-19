### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head) {
            return NULL;
        }

        ListNode pSeudoHead =  ListNode(0);
        pSeudoHead.next  = head;
        ListNode* pBfNextPair = &pSeudoHead;

        while (pBfNextPair->next && pBfNextPair->next->next) {
            pBfNextPair = Swap(pBfNextPair, pBfNextPair->next, pBfNextPair->next->next);
        }
        return pSeudoHead.next;
    }

    ListNode* Swap(ListNode* p1, ListNode* p2, ListNode* p3)
    {
        ListNode* backupP3 = p3->next;
        p1->next = p3;
        p3->next = p2;
        p2->next = backupP3;
        return p2;
    }
};
```