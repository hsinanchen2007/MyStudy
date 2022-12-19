# 73 - 删除列表中的节点

## 题目

请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

![img](https://pic.leetcode-cn.com/d34084b84a2506e9a575589cc88ebc42c2eac5879b6184f321ae5e6b398fc2da.jpg)

示例 1:

> 输入: head = [4,5,1,9], node = 5
> 输出: [4,1,9]
> 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

示例 2:

> 输入: head = [4,5,1,9], node = 1
> 输出: [4,5,9]
> 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.


说明:

- 链表至少包含两个节点。
- 链表中所有节点的值都是唯一的。
- 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
- 不要从你的函数中返回任何结果。

## 解答

这。。感觉好简单啊

就遍历一下，一边遍历一边留一下之前的节点，如果遇到了要删除的，就牵线一下pre和next。。

然后发现。。它只给一个需要删除的node节点。。这样就访问不到之前的节点，并且还要把自己删掉

起码我不知道该怎么写测试代码了。😂😂

### 感觉像脑筋急转弯

官方题解说，把自己的val复制一份，把自己的指针指向下下节点。。假装删了自己，其实是戴着下一个人的面具，把下一个人删了，狸猫换太子。。

```go
func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions forDelete Node in a Linked List.
>
> Memory Usage: 2.9 MB, less than 100.00% of Go online submissions for Delete Node in a Linked List.

```js
var deleteNode = function (node) {
  node.val = node.next.val;
  node.next = node.next.next;
};
```

> Runtime: 68 ms, faster than 29.56% of JavaScript online submissions for Delete Node in a Linked List.
>
> Memory Usage: 36 MB, less than 16.67% of JavaScript online submissions for Delete Node in a Linked List.



> 作者：chitanda-eru
>
> 链接：https://leetcode-cn.com/problems/delete-node-in-a-linked-list/solution/jsxiao-keng-by-chitanda-eru/

js里面还有更简单的方法：

```js
var deleteNode = function (node) {
  Object.assign(node, node.next)
};
```

> Runtime: 60 ms, faster than 77.93% of JavaScript online submissions for Delete Node in a Linked List.
>
> Memory Usage: 35.7 MB, less than 33.33% of JavaScript online submissions for Delete Node in a Linked List.

js的对象都是内存引用，也就是说node这个变量里面，只保留了内存地址，相当于go中的`&node`。

而这个题解中的做法`node = node.next`是不行的，因为这仅仅改变了node的指针指向，让`node`指向了`node.next`的内存地址。即`node`和`node.next`都指向了同一个地方。

`Object.assign()`则是合并两个对象，并覆盖第一个参数所指的地址上。

在这里，就是把`node`和`node.next`合并，并存到`node`所指的内存地址上。合并即相同的属性由`node.next`覆盖`node`，不同的属性都加到`node`上。

如果前面加一个变量，那么这个变量会和`node`所指的内存地址一样。如：`var c = Object.assign(node, node.next)`，那么c指向的是node的地址。改了其中一个，另一个也会改。

![image-20190905140542265](https://pic.leetcode-cn.com/9549a3620ffb12ea7557d2df5da1f2dfcf60ee9033afa30258593aae5bb02566.jpg)



评论里的深浅拷贝，可能理解有错。这两者都是浅拷贝。

所谓深拷贝，是连对象里套的对象也拷贝了，那才叫足够的深，不是么。就好像`var a = {a:1, b:{c:2}}`。深拷贝后，改变了最里面的c，打印a的时候，c也依然会是2。





笑死：

![image-20190905100327070](https://pic.leetcode-cn.com/b7bd18e855f56c3d10fb32d74474cd6ed52fed8969ca1fe55b4378efa1b1875d.jpg)

