解题思路：将后一个节点值复制到删除节点上，将原来的值覆盖

之后出现了两个相同值的节点，故而删除下一个节点即可

代码：
```
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};
```
