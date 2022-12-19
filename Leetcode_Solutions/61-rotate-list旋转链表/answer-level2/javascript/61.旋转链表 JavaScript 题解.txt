
![javascript.jpg](https://pic.leetcode-cn.com/3b622bd5b9a0db72c82ec674ae3d554816eeebc49e4b4f5d666f7b7cb6acfbf6-javascript.jpg)

<br />

> 由于链表无法直接获取长度, 直接循环k次的话又太过耗费性能, 我的思路是分两步走

- 第一次循环:
  - 记录链表长度`n`
  - 让链表闭合形成`环形链表`

- 第二次循环:
  - 循环(k % n)次
  - 然后在该指针处`打断`环形链表, 此时return头部节点就是答案

<br />

```js
const rotateRight = (head, k) => {
  if (!head) return null
  let curr = head, tmp = null, n = 0
  while (curr) {
    n++
    if (!curr.next) {
      curr.next = head
      break
    }
    curr = curr.next
  }
  k = k % n
  while (k++ < n) {
    k === n && (tmp = head)
    head = head.next
  }
  tmp.next = null
  return head
}
```