
![javascript.jpg](https://pic.leetcode-cn.com/4ed0319938e930b7ae0df401161efb798a9e84176e4fbba721aff8ac917de6f6-javascript.jpg)

<br />

- 利用层序遍历+迭代, 一个答案可以解两道题
- 但是一定要从每一层的最后面开始构建

```javascript []
const connect = root => {
  if (!root) return null
  let arr = [root]
  while (arr.length) {
    let tmp = []
    for (let i = 0; i < arr.length; i++) {
      let curr = arr[i]
      curr.next = (i === 0 ? null : arr[i-1])
      curr.right && tmp.push(curr.right)
      curr.left && tmp.push(curr.left)
    }
    arr = tmp
  }
  return root
}
```