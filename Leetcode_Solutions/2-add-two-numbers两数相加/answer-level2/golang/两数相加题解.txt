### 解题思路
难点，边界条件处理，进位的传递。
题目说明是非空列表，所以非空判定可以省略。
尾插法构建结果链表，所以需要先创建一个头节点，其中不包含任何计算结果。


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    // 构建结果链表的第一个节点
    resultNode := &ListNode{
        Val: 0,
    }

    // 进位标识
    extraValue := 0
    resultIter := resultNode
	for {
        // l1和l2均遍历完成
        if l1.Next == nil && l2.Next == nil {
            // 最后一个节点
            resultIter.Next = &ListNode{}
            tempValue := l1.Val + l2.Val +extraValue
            if tempValue > 9 {
                resultIter.Next.Val = tempValue - 10
                resultIter = resultIter.Next

                // 追加新节点
                tmpNode := &ListNode{
                    Val: 1,
                }
                resultIter.Next = tmpNode
                resultIter = resultIter.Next
            } else {
                resultIter.Next.Val = tempValue
                resultIter = resultIter.Next
            }
            break
        }
        
        // 计算当前节点
        resultIter.Next = &ListNode{
            Val: l1.Val + l2.Val + extraValue, 
        }

        // 更新进位标识
        if resultIter.Next.Val > 9 {
            resultIter.Next.Val = resultIter.Next.Val - 10
            extraValue = 1
        } else {
            extraValue = 0
        }

        // 结果链表向前遍历
        resultIter = resultIter.Next

        // l1和l2向前遍历
        l1 = l1.Next
        l2 = l2.Next

        // 有一个遍历完，则退出循环
        if l1 == nil || l2 == nil {
            if l1 == nil {
                resultIter.Next = l2
            } else {
                resultIter.Next = l1
            }

            // 继续处理进位问题
            for true {
                if extraValue == 0 {
                    break
                }

                // 如果已经到了链表末尾，还有进位，则创建新节点
                if resultIter.Next == nil && extraValue == 1{
                    resultIter.Next = &ListNode{
                        Val: 1,
                    }

                    resultIter = resultIter.Next 
                    break
                }

                resultIter.Next.Val = resultIter.Next.Val + 1
                if resultIter.Next.Val > 9 {
                    resultIter.Next.Val = resultIter.Next.Val - 10
                    extraValue = 1
                } else {
                    extraValue = 0
                }
                
                resultIter = resultIter.Next
            }
            break
        }
	}

    return resultNode.Next 
}
```