```go
func deleteNode(node *ListNode) {
    *node = *(node.Next)
}
```