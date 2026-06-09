# 双指针法

	44 ms	7.9 MB

```go
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    nodeA, nodeB := headA, headB
    for nodeA != nodeB {
      if nodeA != nil {
        nodeA = nodeA.Next
      } else {
        nodeA = headB
      }
      if nodeB != nil {
        nodeB = nodeB.Next
      } else {
        nodeB = headA
      }
    }
    return nodeA
}
```

# 切片比较

	44 ms	7 MB

```go
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    ptrsA := []*ListNode{}
    ptrsB := []*ListNode{}
    for headA != nil || headB != nil {
      if headA != nil {
        ptrsA = append(ptrsA, headA)
        headA = headA.Next
      }
      if headB != nil {
        ptrsB = append(ptrsB, headB)
        headB = headB.Next
      }
    }
    ca := len(ptrsA)
    cb := len(ptrsB)
    // boundary
    if ca == 0 || cb == 0 {
      return nil
    }
    nodeOrder := 0
    for ca > 0 && cb > 0 && ptrsA[ca-1] == ptrsB[cb-1] {
      ca--
      cb--
      nodeOrder++
    }
    if nodeOrder == 0 {
      return nil
    }
    return ptrsA[ca]
}
```

理论上应该是双指针法内存消耗小，但是不知道为什么创建两个切片反而少一点