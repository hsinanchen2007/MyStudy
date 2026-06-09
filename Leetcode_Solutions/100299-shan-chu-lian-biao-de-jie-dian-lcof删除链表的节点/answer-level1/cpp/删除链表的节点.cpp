### 解题思路

第一个节点拿出来单独判断即可

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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next;
        ListNode *p = head->next;
        ListNode *pre = head;
        while(p){
            if(p->val == val) pre->next = p->next;
            pre = p;
            p = p->next;
        }
        return head;
    }
};
```