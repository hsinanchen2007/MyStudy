### 解题思路
双指针
指针p1、p2都初始化为head，指针p1先走k步，然后p1与p2一起走，
当p1为NULL时，p2即指向倒数第k个节点

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
    int kthToLast(ListNode* head, int k) {
        
        ListNode* p1 = head;
        ListNode* p2 = head;

        for(int i = 0; i < k; ++i)
        {
            p1 = p1->next;
        }

        while(p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2->val;
    }
};
```