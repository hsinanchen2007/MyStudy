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
func reverseKGroup(head *ListNode, k int) *ListNode {
    dummy := &ListNode{
        Val: -1,
        Next: head,
    }
    pre := dummy
    cur := dummy.Next
    
    for {
        n := k
        // 找出下个部分的头
        nextPart := cur
        for nextPart != nil && n > 0{
            nextPart = nextPart.Next
            n--
        }
        // 如果已经不够 k 个说明可以返回了
        if n > 0{
            break
        }else{
            n = k
        }
        // 保存下个 Pre 节点
        nextPre := cur

        for n > 0{
            // 保存下当前元素的下一个元素
            temp := cur.Next
            // 接上下个头
            cur.Next = nextPart
            // 下个头为当前元素
            nextPart = cur
            // 当前元素为之前临时保留的元素
            cur = temp
            n--
        }
        // n次翻转完毕
        pre.Next = nextPart
        // 设置下个Pre
        pre = nextPre
        cur = pre.Next
    }
    return dummy.Next
}
```