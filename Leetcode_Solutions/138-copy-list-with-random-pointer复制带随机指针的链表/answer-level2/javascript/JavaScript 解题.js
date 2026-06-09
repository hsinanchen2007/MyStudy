
![javascript.jpg](https://pic.leetcode-cn.com/1621f397017744d7086ba8c5f8160c1163e397a319eeec6a5c4e22e77cbbd806-javascript.jpg)

<br />

- 第一次循环拷贝普通属性并记录`random`指针
- 第二次循环按照对应关系给`random`赋值

<br />

```js
const copyRandomList = head => {
  if (!head) return null
  let curr = head, node = new Node(), tmp = node, map = new Map()
  while (curr) {
    tmp.val = curr.val
    tmp.next = curr.next ? new Node() : null
    map.set(curr, tmp)
    tmp = tmp.next
    curr = curr.next
  }
  tmp = node
  while (head) {
    tmp.random = head.random ? map.get(head.random) : null
    head = head.next
    tmp = tmp.next
  }
  return node
}
```
