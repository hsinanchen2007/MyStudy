```cpp []
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```
注意两点：
* 输入的是待删除node
* 将待删除node的值（`val`喝`next`）赋值为下一个node的值，即做到了“删除”

**实质上，这是覆盖。**