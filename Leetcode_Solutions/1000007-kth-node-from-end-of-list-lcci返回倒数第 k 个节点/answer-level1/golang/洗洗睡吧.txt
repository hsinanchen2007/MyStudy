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


// 执行用时 :4 ms, 在所有 Go 提交中击败了 5.30% 的用户
// 内存消耗 :2.3 MB, 在所有 Go 提交中击败了 100.00% 的用户
func kthToLast(head *ListNode, k int) int {
    a:=make([]int,0)
    for ;head!=nil;head=head.Next{
        a=append(a,head.Val)
    }
    return a[len(a)-k]
}


// 执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
// 内存消耗 :2.2 MB, 在所有 Go 提交中击败了 100.00% 的用户
func kthToLast(head *ListNode, k int) int {
    var p1,p2 *ListNode=head,head
    for i:=0;i<k;i++{
        p1=p1.Next
    }
    for ;p1!=nil;p1=p1.Next{
        p2=p2.Next
    }
    return p2.Val
}
```