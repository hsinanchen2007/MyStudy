### 解题思路
双指针，双链表拼接组成长度相容的两个长链表，地址相等处即为所求值

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
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *a = headA; ListNode *b = headB;
        while(a != b){
            if(a == NULL)a = headB;
            else a = a->next;
            if(b == NULL)b = headA;
            else b = b->next;
        }
        return b;
    }
};
```