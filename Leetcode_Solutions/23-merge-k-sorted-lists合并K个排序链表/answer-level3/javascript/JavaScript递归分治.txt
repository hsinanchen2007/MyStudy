其实感觉和MergeSort差不多，只不过合并数组的merge改成了合并两个链表的merge。

首先实现合并两个链表的方法，这里可以参考另外一题的写法：

```javascript
function mergeList (l1, l2) {
  const dummyNode = new ListNode(null)
  let p = dummyNode
  while (l1 && l2) {
    if (l1.val < l2.val) {
      p.next = l1
      l1 = l1.next
    } else {
      p.next = l2
      l2 = l2.next
    }
    p = p.next
  }
  p.next = l1 === null ? l2 : l1
  return dummyNode.next
}
```

然后递归地进行合并：

```javascript
var mergeKLists = function(lists) {
  let left = 0, right = lists.length, mid = ~~((left + right) / 2)
  if (right === 0) return null
  if (right === 1) return lists[0]
  const l1 = mergeKLists(lists.slice(left, mid))
  const l2 = mergeKLists(lists.slice(mid, right))
  return mergeList(l1, l2)
};
```