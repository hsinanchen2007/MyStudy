### 解题思路
链表转数组后进行遍历即可

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
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> nodes;
        ListNode *node = head;
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }

        return nodes[nodes.size() / 2];
    }
};
```