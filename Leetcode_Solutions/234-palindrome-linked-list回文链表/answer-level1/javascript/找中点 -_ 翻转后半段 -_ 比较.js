思路：
（一）找中点
（二）把后半段翻过来
（三）比较 前半段 和 “翻过来的后半段”

## （一）找中点
慢指针每次+1，快指针每次+2。
当快指针走到末尾时，慢指针在中间
```js
let pslow = head;
let pfast = head.next;
while (pfast && pfast.next) {
    pfast = pfast.next.next;
    pslow = pslow.next;
}
```

两种情况：

1. pfast是null。是长度为奇数的链表
![image.png](https://pic.leetcode-cn.com/2050afdd9ac4b870b4735bce181e0d7891399661b41c9332e019d4f5ac9142c8-image.png)

2. pfast有值，但pfast.next是null。是长度为偶数的链表。
![image.png](https://pic.leetcode-cn.com/25778a926d98e88d6d57fc359d92a827e6e6f361147f5016d23c43de8c8ff329-image.png)

无论那种情况：后半段链表的起始节点，都是pslow.next

## （二）把后半段翻过来
```js
// 翻过来的后半段的头结点
let reversedHalfListHead = reverseList(pslow.next);
```
```js
const reverseList = function(head) {
	let lastNode = head;
	let node = head.next;
	while (node) {
		let nextNode = node.next;
		node.next = lastNode;
		lastNode = node;
		node = nextNode;
	}
	return lastNode;
}
```

## （三）比较 前半段 和 “翻过来的后半段”


`while(条件)`这里要小心，p2最终会进入循环：
![image.png](https://pic.leetcode-cn.com/c7621f0ddc54364f3459d1e38eaa6102fab206be47e934a78c4a2f9b4df78f25-image.png)

所以，p2走到pslow.next就必须要停止while了。
这时候，还有一轮需要比较：

```js
let p1 = head;
let p2 = reversedHalfListHead;

// while的条件要小心
while (p2 != pslow.next) {
    // console.log(`p1:${p1.val},p2:${p2.val}`)
    if (p1.val != p2.val) {
        return false;
    }
    p1 = p1.next;
    p2 = p2.next;
}
// 最后再比较一轮
return p1.val === p2.val;
```