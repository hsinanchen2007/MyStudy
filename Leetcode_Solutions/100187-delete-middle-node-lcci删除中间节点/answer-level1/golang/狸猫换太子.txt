思路就是取出当前节点的下一个节点next，将next的val以及next赋值给当前节点node

例如：
```
1->3->4->5
```
假如当前节点为3变化后:
```
1->4->5
    4-^
```
第二行的4是原来的4，可以不用进行删除。

```
func deleteNode(node *ListNode) {
    next := node.Next
    node.Val = next.Val
    node.Next = next.Next
}
```

