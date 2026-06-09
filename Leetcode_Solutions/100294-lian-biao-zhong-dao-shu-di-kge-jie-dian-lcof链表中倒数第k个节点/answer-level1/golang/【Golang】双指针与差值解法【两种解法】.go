# 解法一:双指针

**解题思路：**
**1.定义a和b两个结构体指针，让a先走k次，可得a与b的长度为k**
**2.当a走到nil/null时，b则正好在倒数为k的节点上，返回b即可得到结果**
 
--执行用时:0 ms     --内存消耗：2.2 MB

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    i:=0
    a,b:=head,head
    for a!=nil{
        if i>=k{
            b=b.Next
        }
        a=a.Next
        i++
    }
    return b
}
```
---

# 解法二:

**解题思路：遍历计数后得到链表的长度，利用链表长度与k的差值找到倒数的节点**
 
--执行用时:0 ms     --内存消耗：2.2 MB

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    n:=1    //本题从1开始计数
    cur:=head
    for head.Next!=nil{
        head=head.Next
        n++
    }
    for i:=0;i<n-k;i++{
        cur=cur.Next
    }
    return cur
}
```