### 解题思路
维护两个快慢指针当快指针移动到最后 则用慢指针删除数据

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head == nil{
        return head
    }
    if n <= 0{
        return head
    }

    var(
        h = &ListNode{Val:0,Next:head}
        p = h
        cur = head
        step = 0
    )
       

    //移动到结尾   
    for ; cur != nil; step++ {
        //当step走了大于等于n步的时候开始移动指针
        if step >= n{
            p = p.Next
        }

        cur = cur.Next
    }

    //从倒数第n的前一个位置开始操作删除倒数第n个节点
    del := p.Next
    p.Next = del.Next
    del = nil

    return h.Next
}
```