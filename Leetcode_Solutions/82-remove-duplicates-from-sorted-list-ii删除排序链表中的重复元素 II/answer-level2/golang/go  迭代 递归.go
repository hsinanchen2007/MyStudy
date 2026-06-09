### 解题思路
迭代 递归 
俩种解法
### 代码

```golang

func deleteDuplicates(head *ListNode) *ListNode {
    // 添加前置节点,统一head情况的处理
    prev := &ListNode{0, head} 
    cur := prev
    count := 0
    for(head != nil && head.Next != nil) {
        // 重复的话一直往后
        for (head.Next != nil && head.Val == head.Next.Val ){
            count++
            head=head.Next
        }
        // 有重复的 弄他, 没有继续下一个节点
        if count > 0 {
            cur.Next = head.Next
            head=head.Next
            count = 0
        }else{
            cur = head
            head = head.Next
        }
    }
    return prev.Next
}
```

### 代码

```golang
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    count := 0
    // 重复的话一直往后
    for (head.Next != nil && head.Val == head.Next.Val ){
        count++
        head=head.Next
    }
    // 有重复的 直接不要了， 没有重复的 加等于后面的
    if count > 0 {
        return deleteDuplicates(head.Next)
    }
    head.Next = deleteDuplicates(head.Next)

    return head
}

```