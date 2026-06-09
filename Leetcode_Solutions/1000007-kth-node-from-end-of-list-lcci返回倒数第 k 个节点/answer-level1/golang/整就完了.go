### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 Go 提交中击败了
100.00%
的用户
内存消耗 :
2.2 MB
, 在所有 Go 提交中击败了
100.00%
的用户
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func kthToLast(head *ListNode, k int) int {

    if head.Next == nil {
        return head.Val
    }

    pre := deal(head)
    res := 0
    for pre != nil {
        fmt.Println(pre.Val)
        k--;
        if k == 0 {
            res = pre.Val
            break;
        }
        pre = pre.Next
    }
    return res
}

func deal(head *ListNode) *ListNode{

    //前趋节点
    var pre *ListNode
    var last *ListNode
    for head != nil {
        last = head.Next
        head.Next = pre
        pre = head
        head = last
    }
    return pre
}
```