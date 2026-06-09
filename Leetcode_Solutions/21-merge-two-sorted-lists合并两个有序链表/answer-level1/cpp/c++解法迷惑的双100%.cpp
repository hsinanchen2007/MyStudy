### 解题思路
有点归并那意思
创建一个新的链表头p，指向两链表中val较小的那个，同时两指针后移。
最后记得把p指向较长链表的剩余部分。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )
            return l2;
        if ( l2 == nullptr )
            return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p = new ListNode();
        while ( p1 != nullptr && p2 != nullptr )
        {
            if ( p1->val > p2->val )
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
            
        }
        if ( p1 != nullptr )
            p->next = p1;
        
        if ( p2 != nullptr )
            p->next = p2;

        return l1->val > l2->val ? l2 : l1;
    }
};
```