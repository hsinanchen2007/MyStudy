列表处理

```javascript []
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  if (!head) return null
  let list = []
  while (head) {
    list.push(head)
    head = head.next
  }
  list.reverse()
  for (let i = 0; i < list.length; i++) {
    if (i === list.length - 1) {
      list[i].next = null
    } else {
      list[i].next = list[i + 1]
    }
  }
  return list[0]
}
```
