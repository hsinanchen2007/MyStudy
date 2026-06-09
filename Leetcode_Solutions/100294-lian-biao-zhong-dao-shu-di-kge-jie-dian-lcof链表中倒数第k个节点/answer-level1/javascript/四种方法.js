### 一，快慢指针法

### 二，两次遍历
先遍历一遍获取总长度，然后第二遍遍历时找到目标节点

### 三，链表反转
比如求 1 -> 2 -> 3 -> 4 -> 5 的倒数第二个节点
先把链表反过来变成：5 -> 4 -> 3 -> 2 -> 1
然后找到第二个节点 4
然后以 4 为 head 再次反转就得到了 4 -> 5

### 四，倒序遍历

```javascript
var getKthFromEnd = function(head, k) {
	// 记录当前是倒数第几个节点
	var currIdx = 1;
	var ans = null;
	var postOrder = function(node) {
		if (!node) {
			return;
		}
		postOrder(node.next);
		if (currIdx == k) {
			// 现在遍历到了倒数第 k 个节点，即题目答案
			ans = node;
		}
		currIdx++;
	}

	if (!head || k < 1) {
		return null;
	}
	postOrder(head);
	return ans;
};
```