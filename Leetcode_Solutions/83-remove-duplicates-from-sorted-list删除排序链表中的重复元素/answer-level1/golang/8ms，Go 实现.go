![image.png](https://pic.leetcode-cn.com/de44de7ad70ede0a1782e4f4666006b02b1dc512ca3b98f18f6ab859396a4cca-image.png)

疑惑还要做什么优化才能到 0ms

代码
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    var pre,cur *ListNode = head,nil
    if head != nil {
        cur = head.Next
    }
    for cur!=nil {
        if pre.Val == cur.Val { // 前后元素相等，删除后面的元素
            pre.Next = cur.Next // 不用手动释放被忽略的节点，坐等 Golang 垃圾回收就可以
            cur = pre.Next
        } else {
            pre = pre.Next
            cur = cur.Next
        }
    }
    return head 
}
```