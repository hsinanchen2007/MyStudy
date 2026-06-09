### 解题思路
中序遍历二叉搜索树的结果序列顺序结果正式最终双向循环链表的序列顺序，所以我们可以借助中序遍历的递归实现代码稍作调整，巧妙构造双向链表。为了调整方便，我们需要借助前驱节点引用来与当前节点实现互连。具体实现及说明见代码。

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    Node head,tail,pre; //定义头节点尾节点和前驱节点的引用

	public Node treeToDoublyList(Node root) {
		//根节点为空时，直接返回空值
		if(root == null) 
			return null;
		//中序遍历方式遍历二叉树并将其调整成双向链表
		inOrderAdjust(root);
		//头节点的左指针指向尾节点，尾节点的指针指向头节点，将双向链表变成双向循环链表
		head.left = tail;
		tail.right = head;
		//返回头节点
		return head;
	}
	
	private void inOrderAdjust(Node node) {
		if(node != null) {
			inOrderAdjust(node.left);
			//前驱节点为空时，让头节点指向当前节点，否则前驱节点的右指针指向当前节点
			if(pre == null)
				head = node;
			else
				pre.right = node;
			//当前节点的左指针指向前驱节点
			node.left = pre;
			//前驱节点引用和尾节点引用变为当前节点
			pre = node;
			tail = node;
			inOrderAdjust(node.right);
			return;
		}
	}
}
```