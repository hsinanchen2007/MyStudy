### 解题思路
核心是使用 假节点 

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* cur =  &dummyHead;
        while(l1&&l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        cur->next = l1?l1:l2;
        return dummyHead.next;
    }
};
```