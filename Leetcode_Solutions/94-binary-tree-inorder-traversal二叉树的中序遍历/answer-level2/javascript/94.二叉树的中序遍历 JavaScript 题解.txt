![4ebeae6d9886343826895f48dc0344d39b3bca748392006121b4d48835757240-javascript.jpg](https://pic.leetcode-cn.com/d91f9cd88f67c7d5dc61f352d779a9f74413de800634d8a9903af6dba43f826a-4ebeae6d9886343826895f48dc0344d39b3bca748392006121b4d48835757240-javascript.jpg)

<br />

> 这规律够难找的....

<br />

- 如果left节点存在, 就入栈, 然后跳left
- 如果left和right都不存在, 则保存当前节点, 然后出栈, 并让left等于null
- 如果right节点存在, 并且left为null, 则保存当前节点, 然后跳right

![20190811142322.jpg](https://pic.leetcode-cn.com/7d8bdfe3b16d58822b7f901b026d292ec2babb6f4cbd146eef3a6087bf892789-20190811142322.jpg)

```javascript []
const inorderTraversal = root => {
  let res = [], stack = []
  while (root || stack.length) {
    if (root.left) {
      stack.push(root)
      root = root.left
    } else if (!root.left && !root.right) {
      res.push(root.val)
      root = stack.pop()
      root && (root.left = null)
    } else if (root.right) {
      res.push(root.val)
      root = root.right
    }
  }
  return res
}
```
