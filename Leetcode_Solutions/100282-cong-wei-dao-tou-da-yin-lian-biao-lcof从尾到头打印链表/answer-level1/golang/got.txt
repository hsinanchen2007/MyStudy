### 解题思路
o(n)
递归解法最简单，注意使用全局变量有坑

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    if head==nil{
        return []int{}
    }
    return append(reversePrint(head.Next),head.Val)
}
```