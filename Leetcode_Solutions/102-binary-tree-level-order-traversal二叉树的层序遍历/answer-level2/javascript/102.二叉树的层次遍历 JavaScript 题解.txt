
![javascript.jpg](https://pic.leetcode-cn.com/9d59b6a9105d01685fc5fa9fe4c88af992ecfd04eb55c3f23ec464502d22e854-javascript.jpg)

<br />

> 迭代才能体现出`广度优先搜索`的优雅性, 我的思路是:

- 使用队列存放每一层的节点, 然后在循环中记录值, 并且把子节点添加进去
- 外循环负责遍历层级结构, 内循环负责遍历每一层的子节点
- 最后把`temp`下一层的节点, 再赋给`queue`, 直到`queue`为空则表示全部遍历完毕

![20190813145044.png](https://pic.leetcode-cn.com/9ac80118d9770d03a78ced86d471125dc1be7f3cf4ce209e7f5b94acbef3f37b-20190813145044.png)

```javascript []
const levelOrder = root => {
  if (!root) return []
  let res = [], queue = [root]
  while (queue.length) {
    let arr = [], temp = []
    while (queue.length) {
      let curr = queue.shift()
      arr.push(curr.val)
      if (curr.left) temp.push(curr.left)
      if (curr.right) temp.push(curr.right)
    }
    queue = temp
    res.push(arr)
  }
  return res
}
```
