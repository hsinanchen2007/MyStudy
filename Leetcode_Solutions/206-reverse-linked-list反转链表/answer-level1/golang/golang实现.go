## 迭代法和递归实现

```
//迭代法（核心思想就是从第二个节点开始，将节点放到头节点）
func reverseList(head *ListNode) *ListNode {
    var pre *ListNode //当前节点之前
    var curr = head //当前节点
    for curr!=nil{
        next:=curr.Next//保留一个指向下一个节点的指针
        curr.Next=pre//将当前节点指向它前面的节点
        pre = curr//前指针后移
        curr=next//当前指针后移
    }
    return pre
}

//改进版
func reverseList2(head *ListNode)*ListNode{
    var pre *ListNode
    var curr=head
    for curr!=nil{
        curr.Next,pre,curr=pre,curr,curr.Next
    }
    return pre
}

//递归反转链表
func reverse(pre,curr *ListNode)*ListNode{
    if curr==nil{
        return pre
    }
    next:=curr.Next
    curr.Next=pre
    return reverse(curr,next)
}

func reverseList3(head *ListNode)*ListNode{
    return reverse(nil,head)
}
```
