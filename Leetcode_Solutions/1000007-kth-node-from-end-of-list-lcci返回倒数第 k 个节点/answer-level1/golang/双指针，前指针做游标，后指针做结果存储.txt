解题思路：
![image.png](https://pic.leetcode-cn.com/a397a5a751402bf43b5303cb1cc8b18f0bf27cda408f3a70cfd4b85123fe1600-image.png)

使用快慢两个指针p, q。p移动到第k个元素，然后保持p, q 保持 1、k差距，然后同时移动p, q. 当p=nil时，q就是倒数第k个元素

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func kthToLast(head *ListNode, k int) int {
    var p,q *ListNode= head, head
    for i:=0;i<k;i++ {
        p = p.Next
    }
    for ;p!=nil; {
        p = p.Next
        q = q.Next
    }
    return q.Val
}
```
