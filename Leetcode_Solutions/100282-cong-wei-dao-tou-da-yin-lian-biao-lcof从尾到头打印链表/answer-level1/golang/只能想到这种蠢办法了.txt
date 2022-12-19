### 解题思路
数组和切片原来不是一个东西啊。。。切片只能在后面插数字，如果是头插的话，插入的也必须是切片，所以只能先插进去，然后把切片倒序。。。。。。

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
    ans := make([]int,0)  
    for{
        if nil == head {break}
        ans = append(ans,head.Val)
        if head.Next == nil{
            break
        }
        head = head.Next
    }

    for i:= 0 ; i < len(ans)/2; i++{
        tmp := ans[i]
        ans[i] = ans[len(ans)-1-i]
        ans[len(ans)-1-i] = tmp
    }

    return ans
}
```