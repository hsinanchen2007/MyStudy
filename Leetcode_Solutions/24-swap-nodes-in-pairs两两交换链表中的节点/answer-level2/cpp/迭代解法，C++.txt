### 解题思路
简洁的迭代解法，添加一个空头，再保存前后的两个节点

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
    ListNode* swapPairs(ListNode* head) {
        ListNode pre(0);
        ListNode *prep = &pre, *curr = head, *after;
        prep->next = head;
        while (curr && curr->next){            
            after = curr->next->next;
            prep->next = curr->next;
            prep->next->next = curr;
            curr->next = after;
            prep = curr;
            curr = prep->next;
        }
        return pre.next;
    }
};
```