### 解题思路

1，将链表里的值顺序`append`进事先声明好的`re`数组；  
2，将`re`数组中的值倒序`append`进`er`数组后，返回。

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
    var re []int
    var er []int
    for ;head != nil; {
        re = append(re,head.Val)
        head = head.Next
    }
    for i:=len(re)-1;i>=0;i-- {
        er = append(er,re[i])
    }
    return er
}
```