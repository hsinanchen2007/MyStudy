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
        //先把node与node+1的val互换
        ListNode *p = node->next;
        int temp = p->val;
        p->val = node->val;
        node->val = temp;

        //把node+1节点删除
        node->next = p->next;
        delete p;
    }
};
```