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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    map<ListNode *,int> M;
    if (!headA&&!headB) return NULL;
    if (!headA||!headB) return NULL;
    while (headA) {
        M[headA]++;
        headA=headA->next;
    }
    while (headB) {
        if (M[headB]==1) {
            return headB;
        }
        headB=headB->next;
    }
    return NULL;
}
};
```