
```golang []
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    ans := &ListNode{0, head}
    for ; n > 0; n -- {
        head = head.Next
    }
    tmp := ans
    for head != nil{
        head = head.Next
        tmp = tmp.Next
    }
    tmp.Next = tmp.Next.Next
    return ans.Next
}
```
![image.png](https://pic.leetcode-cn.com/2af4805745472056d748a07fefcaf316a3e9148466112726ed60f91a8e69a022-image.png)
