
## 非递归写法

如下图，不难看出，反转需要这么几个步骤：

1. 将c节点的指针改为p
2. 将p节点移动到c节点
3. 将c节点移动到下一个节点n
4. 此时我们反转了图中第一个链接，并且断开来1和2之间的指针。重复上面几个步骤，直到c节点为null，此时p节点即新的header

```
null ---> 1 ---> 2 ---> 3 ---> 4 ---> 5
 |        |      ｜
 p        c      n
```
转化成代码就是：
```
c.next = p
p = c
c = n
```
上面的代码放在一个while循环里跑一遍，直到c为null即可。注意到代码里只有n这个变量是缺少定义的，因为每次循环开始，我们都可以通过c.next直接访问到n。当然，因为第一步我们就把c.next的指向改了，所以需要一个临时变量来存储n的位置。

```javascript
const reverseList = head => {
  let p = null, c = head
  while (c) {
    let temp = c.next
    c.next = p
    p = c
    c = temp
  }
  return p
}
```

评论区里有个很巧妙的python解法，使用解构的语法，省去了`temp`这个变量的定义。同样的，在js中我们也可以这么写：

```javascript
var reverseList = function(head) {
  let [p, c] = [null, head]
  while (c) {
    [p, c.next, c] = [c, p, c.next]
  }
  return p
};
```

不过由于目前而言，解构语法的性能消耗较大，所以这个写法的运行效率会低很多。


## 递归解法

递归解法的一贯套路：在开始之前，假设我们已经解决了这个问题，即有一个函数`reverseList`，可以成功地反转链表。

那么对于如下链表，如果我们对第二个节点应用这个函数，会发生什么呢？
```
1 ---> 2 ---> 3 ---> 4 ---> 5
```
会变成这样：
```
1 ---> 2 <--- 3 <--- 4 <--- 5
```
并且其返回值`reverseList(node2)`就是新的头节点，5号节点。所以剩下的工作就很简单了，只要将1的后继节点改为null，再将2的后继节点改为1即可。

同时，我们的前面的讨论都是建立在head与head.next都存在的情况下的，所以这两种情况要单独处理，也是递归的出口。

```javascript
const reverseList = head => {
  if (!head || !head.next) return head
  const p = reverseList(head.next)
  head.next.next = head
  head.next = null
}
```