### 解题思路
此处撰写解题思路

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
    void deleteNode(ListNode* node) {
        //既然是非末尾且为有效结点 那就不用额外判断了
        //因为不知道前一个指针 所以把后一个节点复制过来 删后一个节点就好
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```