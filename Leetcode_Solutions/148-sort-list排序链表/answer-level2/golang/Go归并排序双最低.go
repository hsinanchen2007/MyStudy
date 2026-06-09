![image.png](https://pic.leetcode-cn.com/e1c94187c5207d7c78e3588ad944eef6ac743ecd9b57ba73d19e93269bbc6c8a-image.png)
```
func sortList(head *ListNode) *ListNode {
    if head==nil||head.Next==nil{
        return head
    }
    //使用归并排序
    //使用快慢指针将链表分为两段
    var slow,fast = head,head
    for fast!=nil&&fast.Next!=nil&&fast.Next.Next!=nil{
        slow,fast = slow.Next,fast.Next
    }
    var tail = slow.Next
    slow.Next = nil
    //递归
    return mergeTwoLists(sortList(head),sortList(tail))
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1==nil&&l2==nil{
        return nil
    }
    var head = new(ListNode)
    ptr := head
    for l1!=nil&&l2!=nil{
        if l1.Val<l2.Val{
            head.Next = l1
            head = head.Next
            l1 = l1.Next
        }else{
            head.Next = l2
            head = head.Next
            l2 = l2.Next
        }
    }
    if l1!=nil{
        head.Next = l1
    }
    if l2!=nil{
        head.Next = l2
    }
    return ptr.Next
}
```
