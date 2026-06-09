### 解题思路

Go: 16ms(50%), 5.1MB(100%)

**归并排序——非递归实现思路**：我们知道，二路归并的递归实现思想是从整体到局部，非递归实现正好相反，从局部到整体。

![image.png](https://pic.leetcode-cn.com/0aa8ad1b00469807b76c9438a06512d1406e233a55265c679a4968e1a4c7c791-image.png)

基于上图，非递归实现简单说就是多个有序子序列不断合并，最终达到整体有序。


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    length := 0
    for node := head; node != nil; node = node.Next {
        length++
    }

    nilHead := new(ListNode)
    nilHead.Next = head
    pre := nilHead
    cur := pre.Next
    for k := 1; k < length; k = 2 * k {
        pre = nilHead
        cur = pre.Next
        for cur != nil {
            // 获取第一条长度为k的子链
            list1 := cur
            tail := cur
            for i := 1; i < k && tail != nil; i++ {
                tail = tail.Next
            }
            // 当第2条子链为空时直接退出循环，说明无需合并
            if tail == nil || tail.Next == nil {
                break
            }
            
            // 获取第二条长度小于等于k的子链
            list2 := tail.Next
            tail.Next = nil
            tail = list2
            for i := 1; i < k && tail != nil; i++ {
                tail = tail.Next
            }

            // cur指向余下的待排序归并的右子链，并且与第二条待排序归并子链断开
            if tail != nil {
                cur = tail.Next
                tail.Next = nil
            } else {
                cur = nil
            }

            // 对list1, list2进行归并排序并将其用pre连接在一起
            pre.Next = merge(list1, list2)
            if cur != nil {
                // 将排序后的子链与待排序的右子链连接起来
                tail = pre.Next
                for tail.Next != nil {
                    tail = tail.Next
                }
                pre = tail
                tail.Next = cur
            }
        }
    }

    return pre.Next
}

func merge(list1, list2 *ListNode) *ListNode {
    if list1 == nil || list2 == nil {
        if list1 != nil {
            return list1
        } else if list2 != nil {
            return list2
        } else {
            return nil
        }
    }

    var head, tail, less *ListNode
    for list1 != nil && list2 != nil {
        if list1.Val <= list2.Val {
            less = list1
            list1 = list1.Next
        } else {
            less = list2
            list2 = list2.Next
        }
        if head == nil {
            head = less
            tail = less
        } else {
            tail.Next = less
            tail = less
        }
    }

    if list1 != nil {
        tail.Next = list1
    }
    if list2 != nil {
        tail.Next = list2
    }

    return head
}
```