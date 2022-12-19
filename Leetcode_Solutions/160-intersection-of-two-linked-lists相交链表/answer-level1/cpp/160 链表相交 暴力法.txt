### 解题思路
用set存储过往节点
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
        set<ListNode *> s;
        while (headA || headB) {
            if (headA) {
                if (s.find(headA)!=s.end()) return headA;
                s.insert(headA);
                headA = headA->next;
            }
            if (headB) {
                if (s.find(headB)!=s.end()) return headB;
                s.insert(headB);
                headB = headB->next;
            }            
        }
        return NULL;
    }
};
```