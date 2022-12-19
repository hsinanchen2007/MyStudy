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
func kthToLast(head *ListNode, k int) int {
    arr:=[]int{}
    for head!=nil{
        arr=append(arr,head.Val)
        head=head.Next
    }
    return arr[len(arr)-k]
}
```