### 解题思路
代码一看就懂，这里就只分析复杂度
    时间：O(1)
    空间：O(1)

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
    //原来还思考为什么没有给出head呢。
    void deleteNode(ListNode* node) {
       node->val = node->next->val;
       ListNode* willDelete = node->next;
       node->next = node->next->next;
       delete willDelete;
       return;
    }
};
```