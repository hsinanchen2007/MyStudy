### 解题思路
- 核心思路：两个指针遍历两个链表，到尾时再遍历另一个链表，直到两指针重合
- 执行用时：96 ms, 在所有 C++ 提交中击败了23.45%的用户
- 内存消耗：14.6 MB, 在所有 C++ 提交中击败了100.00%的用户
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
        ListNode*p=headA;
        ListNode*q=headB;
        while(p!=q){
            p=p==NULL?headB:p->next;
            q=q==NULL?headA:q->next;
        }
        return p;
    }
};
```