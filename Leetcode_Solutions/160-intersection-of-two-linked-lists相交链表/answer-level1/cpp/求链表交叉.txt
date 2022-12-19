### 解题思路
1、 a + b = b + a
2、先找到一个链表的尾指针，然后构建环，再用慢指针找

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
        if(!headA || !headB){
            return NULL;
        }

        ListNode* tailA = headA;
        ListNode* tailB = headB;

        while(tailA != tailB){
            tailA = (tailA ? tailA->next : headB);
            tailB = (tailB ? tailB->next : headA);
        }

        return tailA;

    }
};
```