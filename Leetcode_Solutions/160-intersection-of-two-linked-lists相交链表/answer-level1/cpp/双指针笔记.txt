### 解题思路
看过一次，还是忘记了双指针的用法。此处做笔记：
A->B = a->c->b->c
B->A = b->c->a->c

len(a->c->b) = len(b->c->a)

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
        ListNode *a = headA, *b = headB;
        
        if (a == NULL || b == NULL)
            return NULL;
        
        while (a != b) {
            if (a == NULL)
                a = headB;
            else
                a = a->next;
            
            if (b == NULL)
                b = headA;
            else
                b = b->next;
        }
        
        return a;
    }
};
```