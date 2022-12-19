声明两个指针，其中一个每次走两步，另一个每次走一步，如果链表存在环，那么他们肯定会在某处相遇。
注意一定要处理好指针指向空的情况。

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* h1 = head;
        ListNode* h2 = head;
        while(h1 != NULL && h2 != NULL && h1->next != NULL && h2 -> next != NULL) {
            h1 = h1->next->next;
            h2 = h2->next;
            if(h1 == h2) {
                return true;
            }
        }
        return false;
    }
};
```
