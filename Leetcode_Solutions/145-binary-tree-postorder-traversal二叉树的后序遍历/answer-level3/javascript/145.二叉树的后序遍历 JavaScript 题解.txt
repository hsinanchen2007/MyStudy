
![javascript.jpg](https://pic.leetcode-cn.com/cd3a6484c4c44ebbcbbff455cecb185963159a7e1ddfd49c3a2a818a94c15d20-javascript.jpg)

<br />

> 我的思路: 正序解  


1, 先遍历左节点, 当遍历到末尾节点时, 记录值
2, 然后跳回上一层节点, 顺便让left等于null
3, 再遍历右节点, 同样是遍历到末尾节点时, 记录值
4, 第二次返回时, 让右节点等于null

![20190812180312.png](https://pic.leetcode-cn.com/e41d3ab598cdebf7c817e6e06a8b18b6fb264ba1e56f272597056d5ae63d95a1-20190812180312.png)

通过这种人为的方式, 不断的创造末尾节点记录值

```javascript []
const postorderTraversal = root => {
  let res = [], stack = []
  while (root || stack.length) {
    if (root.left) {
      stack.push(root)
      root = root.left
    } else if (root.right) {
      stack.push(root)
      root = root.right
    } else {
      res.push(root.val)
      root = stack.pop()
      if (root && root.left) root.left = null
      else if (root && root.right) root.right = null
    }
  }
  return res
}
```

<br />

> 别的大佬的思路: 倒序解


- 大佬的思路清奇, 简单, 灵活, 简直就是前序遍历的翻版
- 每次先入左节点, 然后入右节点
- 每次把值都插到数组的最前面

```javascript []
const postorderTraversal = root => {
  let res = [], stack = []
  while (root || stack.length) {
    res.unshift(root.val)
    if (root.left) stack.push(root.left)
    if (root.right) stack.push(root.right)
    root = stack.pop()
  }
  return res
}
```
