
![javascript.jpg](https://pic.leetcode-cn.com/4ebeae6d9886343826895f48dc0344d39b3bca748392006121b4d48835757240-javascript.jpg)

<br />

> 双链表遇到二叉树, 真是像极了爱情

<br />

![20190726103634.png](https://pic.leetcode-cn.com/7b0073189d71f54fb0497d71893bbb02ab1c0831a8c55add934822157f0e6fc1-20190726103634.png)

<br />

- 思路很简单
  - 遇到child就递归, 把next和child都传递过去, 因为指针会遍历到后面, 正好可以拼接next和child
  - 递归返回之后要清掉child, 并且处理好prev指针

<br />

## 耗时1636ms, 击败95%

```js
// 优化前
const flatten = (head, next) => {
  let curr = head
  while (curr && (curr.next || curr.child)) {
    if (curr.child) {
      curr.next = flatten(curr.child, curr.next)
      curr.child = null
      curr.next.prev = curr
    }
    curr = curr.next
  }
  if (next) {
    next.prev = curr
    curr.next = next
  }
  return head
}
```

<br />

## 代码优化一下, 耗时1564ms, 击败了100%

<br />

我在使用vscode调试的时候, 发现指针走的顺数跟我想的不太一样  

括号里面就是多出来的部分, 指针走了不必要的路径, 如果链表更加复杂, 性能无疑是大大的浪费  

```
我想的是:
1 -> 2 -> 3 -> 7 -> 8 -> 11 -> 12 -> 9 -> 10 -> 4 -> 5 -> 6

实际上:
1 -> 2 -> 3 -> 7 -> 8 -> 11 -> 12 -> (8 -> 11 -> 12) -> 9 -> 10 -> (3 -> 7 -> 8 -> 11 -> 12 -> 9 -> 10) -> 4 -> 5 -> 6
```

<br />

> 于是我使用了额外的变量来存储递归返回的指针(因为在内层的方法中, 指针已经走到了最后)

```js
// 优化后
const flatten = (head, next) => {
  let curr = head
  while (curr && (curr.next || curr.child)) {
    if (curr.child) {
      let res = flatten(curr.child, curr.next)
      let tmp = curr.next
      curr.next = res
      curr.child = null
      curr.next.prev = curr
      curr = tmp
    } else {
      curr = curr.next
    }
  }
  if (next) {
    next.prev = curr
    curr.next = next
  }
  return head
}
```

<br />

![20190726104903.png](https://pic.leetcode-cn.com/7ef6b364f8cc6bb33d2dd68a986db94eee616e6e63609cd7f592ad287cc59793-20190726104903.png)

