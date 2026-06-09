### 解题思路

Go: 0ms(100%), 3.1MB(100%)

需要注意的是，如果使用头插法往数组中添加元素，则会因内存分配耗时较长(50多ms)。优化策略有两种：
1. 先尾插法，然后首尾双指针交换值
2. 先求出链表长度，然后从后往前放节点值，省去了逆置这一步

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    if head == nil {
        return nil
    } else if head.Next == nil {
        return []int{head.Val}
    }

    values := make([]int, 0)
    for head != nil {
        values = append(values, head.Val)
        head = head.Next
    }

    for left, right := 0, len(values) - 1; left < right; left, right = left + 1, right - 1 {
        values[left], values[right] = values[right], values[left]
    }

    return values
}
```