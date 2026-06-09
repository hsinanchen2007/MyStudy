![1.PNG](https://pic.leetcode-cn.com/caa05e59c9e6462712aee0a8138df314a685298c88fdddc0128f081f40c6ae9f-%E6%8D%95%E8%8E%B7.PNG)


### 解题思路
遍历二进制链表，输出结果

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    val := int(0)
    for l := head;l != nil;l= l.Next {
        val = val * 2 + l.Val
    }
    return val
}
```