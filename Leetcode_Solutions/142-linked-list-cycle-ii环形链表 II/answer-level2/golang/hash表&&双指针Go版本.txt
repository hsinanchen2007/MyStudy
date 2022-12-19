1.hash表
```
func detectCycle(head *ListNode) *ListNode {
    nodeExist := make(map[*ListNode]int)
    cur := head
    for cur != nil {
        if _, exist := nodeExist[cur]; exist {
            return cur
        }
        nodeExist[cur] = 1
        cur = cur.Next
    }
    return nil    
}
```
2.双指针
![99999.jpg](https://pic.leetcode-cn.com/c1c7489f54bfaf281677e692578f03501a676464d1b9e7a04dfebaa0533b85e7-99999.jpg)
F = b + 1

```
func detectCycle(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return nil
    }

    slow, fast := head, head.Next
    for slow != fast {
        if fast == nil || fast.Next == nil {
            return nil
        }

        slow = slow.Next
        fast = fast.Next.Next
    }

    ptr1, ptr2 := head, slow.Next
    for ptr1 != ptr2 {
        ptr1 = ptr1.Next
        ptr2 = ptr2.Next
    }

    return ptr1
} 
```
```
func detectCycle(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return nil    
    }
    
    slow, fast := head, head
    for fast.Next != nil && fast.Next.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next

        if slow == fast {
            ptr1 := head
            for ptr1 != slow {
                ptr1 = ptr1.Next
                slow = slow.Next
            }

            return ptr1
        }
    }

    return nil   
}
```


