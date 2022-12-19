### 解题思路
这题不用费心自己构建链表，为了删掉当前的节点，可以将后一个节点的数据域复制过来，然后直接连接到下下个节点，即实现当前节点和下一个节点的对调，然后删掉下一个节点。
### 代码

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```