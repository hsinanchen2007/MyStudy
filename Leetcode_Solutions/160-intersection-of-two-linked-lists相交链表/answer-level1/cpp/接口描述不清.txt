### 解题思路
地址完全相同，数据不一样，接口描述不清

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

        if(headA == nullptr || headB == nullptr) 
            return nullptr;

        ListNode* cur_a = headA;
        ListNode* cur_b = headB;

        while(cur_a != cur_b)
        {
            cur_a = (cur_a == nullptr ? headB : cur_a->next);
            cur_b = (cur_b == nullptr ? headA : cur_b->next);
        }

        return cur_a;
    }
};
```