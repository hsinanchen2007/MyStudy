### 解题思路
pa, pb 同时走，如果pa到头， 就把pa放到headB，再同时走； 如果pb到头就放到headA，再同时走，只要有交点，总会相遇的。如果没有焦点，pa == pb == NULL，退v出。

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
        ListNode *pa = headA, *pb = headB;                              // 双指针 交替遍历
        while ( pa != pb ) {
            pa = (pa != NULL ? pa -> next : headB);
            pb = (pb != NULL ? pb -> next : headA);
        }
        return pa;          // 不需要边界处理， 没有焦点， pa就是NULL
    }
};
```