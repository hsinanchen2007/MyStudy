### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
    var head = node
    var lens int
    // 后面的元素值赋给自己
    for head.Next != nil {
        lens ++
        head.Val = head.Next.Val
        head = head.Next
    }
    head = node
    // 删除最后一个节点
    for i:=0; i<lens-1; i++{
        head = head.Next
    }
    head.Next = nil
}
```