## 方法1：反转后半段
```golang
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }
    // 利用快慢指针将后半段反转，然后一一比较
    slow := head
    fast := head

    for fast.Next != nil && fast.Next.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    //123456
    //链表是偶数: fast == 倒数第二个元素, slow == 前半段的最后一个
    //链表是奇数: fast == 倒数第一个元素, slow == 中间元素
    //保存slow此时的点, 可能会用到
    temp := slow

    //让slow.next作为后半段的头元素，然后反转后半段链表
    newHead := reverse(slow.Next)
    slow = newHead
    fast = head

    for slow != nil {
        if slow.Val != fast.Val {
            return false
        }
        slow = slow.Next
        fast = fast.Next
    }
    
    //把链表恢复原样, 接在temp的后面
    temp.Next = reverse(newHead)
    
    return true

}

func reverse(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    var pre  *ListNode
    var temp *ListNode
    for head != nil {
        temp = head.Next
        head.Next = pre
        pre = head
        head = temp
    }
    return pre
}
```

## 方法2：反转前半段
```golang
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }

    //利用快慢指针将前半段反转, 得到分别得到前后两段的头指针，然后逐一比较

    // 1. 利用快慢指针将前半段反转
    slow, fast := head, head
    var temp, pre *ListNode

    for fast != nil && fast.Next!= nil {
        // 1.先让快指针走两步
        fast = fast.Next.Next

        // 2.反转，并且让slow后移一位
        temp = slow.Next
        slow.Next = pre
        pre = slow
        slow = temp
    }

    //1234
    //链表长度为偶数: fast是nil，slow是后半段第一个
    //链表长度为奇数: fast是倒数第一个元素，slow是中间元素

    //所以
    //if fast == nil {//偶数
        //pre是前半段的头
        //slow是后半段的头
    //} else {//奇数, slow在中间
        //pre是前半段的头
        //slow的next是后半段的头
    //}
	
	
	//保存连接点，以便恢复链表
    p1 := pre
    p2 := slow

    if fast != nil {
        slow = slow.Next
    }

    //此时
    //pre 是前半段的头
    //slow是后半段的头
    res := true
    for slow != nil {
        if slow.Val != pre.Val {
            res = false
            break
        }
        slow = slow.Next
        pre = pre.Next
    }

    //恢复链表
    //把以p1为头的链表反转,并和后半段连接
    pre = p2
    for p1 != nil {
        temp = p1.Next
        p1.Next = pre
        pre = p1
        p1 = temp
    }

    return res
}
```

## 方法3: 用defer函数对方法2优化
```golang
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }

    slow, fast := head, head
    var temp, pre *ListNode

    for fast != nil && fast.Next!= nil {
        // 1.先让快指针走两步
        fast = fast.Next.Next

        // 2.反转，并且让slow后移一位
        temp = slow.Next
        slow.Next = pre
        pre = slow
        slow = temp
    }

    //保存连接点，以便恢复链表
    //p1 := pre
    //p2 := slow
    
    defer func(p1, p2 *ListNode){
        //恢复链表
        //把以p1为头的链表反转,并和后半段连接
        pre = p2
        for p1 != nil {
            temp = p1.Next
            p1.Next = pre
            pre = p1
            p1 = temp
        }
    }(pre, slow)
    

    if fast != nil {
        slow = slow.Next
    }

    for slow != nil {
        if slow.Val != pre.Val {
            return false
        }
        slow = slow.Next
        pre = pre.Next
    }

    return true
}

```

