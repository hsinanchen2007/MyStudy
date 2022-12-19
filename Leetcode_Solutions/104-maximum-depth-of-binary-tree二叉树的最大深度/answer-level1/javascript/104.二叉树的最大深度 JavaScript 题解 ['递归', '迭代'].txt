
![javascript.jpg](https://pic.leetcode-cn.com/cc0450d884c0b1859adb21cd8cc5dda72eb1133ce891fef07749f15fa0858e8b-javascript.jpg)

<br />

> 首先看递归

- 比较求值

```javascript []
const maxDepth = (root, n = 0) => {
  if (!root) return 0
  n++
  let n1 = 0, n2 = 0
  if (root.left) n1 = maxDepth(root.left, n)
  if (root.right) n2 = maxDepth(root.right, n)
  return Math.max(n, n1, n2)
}
```

<br />

> 然后看迭代

- 利用层序遍历累加

```javascript []
const maxDepth = root => {
  if (!root) return 0
  let queue = [root], n = 0
  while (queue.length) {
    let arr = []
    while (queue.length) {
      let curr = queue.shift()
      if (curr.left) arr.push(curr.left)
      if (curr.right) arr.push(curr.right)
    }
    n++
    queue = arr
  }
  return n
}
```
