```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    s1 := initStack(l1)
    s2 := initStack(l2)
    preHead := &ListNode{}
    carry := 0
    for {
        if len(s1) == 0 && len(s2) == 0 && carry == 0{
            break
        }
        v1 := popValue(&s1)
        v2 := popValue(&s2)
        sum := v1 + v2 + carry
        node := &ListNode{Val: sum % 10}
        node.Next = preHead.Next
        preHead.Next = node
        carry = sum / 10
    }
    return preHead.Next
}

func initStack(head *ListNode) []int {
    var stack []int
    for {
        if head == nil {
            break
        }
        stack = append(stack, head.Val)
        head = head.Next
    }
    return stack
}

func popValue(stack *[]int) int {
    length := len(*stack)
    var lastValue int
    if length > 0 {
        lastIndex := length - 1
        lastValue = (*stack)[lastIndex]
        *stack = (*stack)[:lastIndex]
    }
    return lastValue
}
```
