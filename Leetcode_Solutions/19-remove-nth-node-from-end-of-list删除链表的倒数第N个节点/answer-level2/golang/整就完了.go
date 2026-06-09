### 解题思路
此处撰写解题思路

1、主要是你返回的是一个头结点，你如果直接拿head一把梭操作以后，head的节点就变了
2、所以第一步把冰箱门打开，哦不，建立一个空头结点res，让一个pre指针指向这个空头结点，之后再操作pre
3、一顿操作以后，注意返回res.Next，而不是res

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    //倒数第二个元素是正数的 len-2+1个元素，这个需要你细品一下

    var size int
    cur := head
    //头结点
    var res = new(ListNode)
    pre := res
    for cur != nil {
        size++
        cur = cur.Next
    }

    for i := 0; i < size - n; i++ {
        fmt.Println("head == ", head.Val)
        pre.Next = head
        head = head.Next
        pre = pre.Next
        fmt.Println("pre == ", pre.Val)
    }
    pre.Next = head.Next //这里刚开始写了 pre = head.Next 输出的是【1,2,3,4,5】，改成pre.Next = head.Next就对了，得品一下这里
    fmt.Println("pre == ", pre.Val)
    return res.Next
}
```