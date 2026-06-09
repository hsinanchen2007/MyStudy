如果两个链表长度相同，那么挨个比较，就能找到相交节点了。

难点：**如果两个链表长度不同，怎么办？**

## 思路一 	
先算出A、B链的长度
假设A链长度为10，B链长度为8，那么跳过A链的前两个节点

```js

var getIntersectionNode = function(headA, headB) {
	const difference = getLinkedListLength(headA) - getLinkedListLength(headB);
	// 长的链表，需要先跳过前几个节点
	let node1 = headA;
	let node2 = headB;
	for (let i = 1; i <= Math.abs(difference); i++) {
		if (difference > 0) {
			node1 = node1.next;
		} else {
			node2 = node2.next;
		}
	}
	// 逐个比较
	while (node1 && node2) {
		if (node1 === node2) {
			return node1;
		}
		node1 = node1.next;
		node2 = node2.next;
	}
	return null;
};

var getLinkedListLength = function(head) {
	let ans = 0;
	let node = head;
	while (node) {
		ans++;
		node = node.next;
	}
	return ans;
}
```

## 思路二
构造两个新链表，长度相等。

### 构造方法
把两个原始链表分别记为A、B：

新链表1：沿着A走，A走完了之后再沿着B走

新链表2：沿着B走，B走完了之后再沿着A走

![image.png](https://pic.leetcode-cn.com/10754d27609cb071e21a8b37e851194ecf62e34f32ade9404d47eacda4a7b866-image.png)

```js
var getIntersectionNode = function(headA, headB) {
	let p1 = headA;
	let p2 = headB;
	// 如果没有相交，那么走到最后 p1和p2会同时变为null 也会跳出循环
	while (p1 != p2) {
		p1 = p1 ? p1.next : headB;
		p2 = p2 ? p2.next : headA;
	}
	return p1;
};
```
