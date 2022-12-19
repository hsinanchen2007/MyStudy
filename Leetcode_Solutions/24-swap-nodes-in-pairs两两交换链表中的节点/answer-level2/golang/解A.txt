### 解题思路
+ a -> b -> c -> d
    1. for 1
    2. a -> d,
    3. b -> a,
    4. for 2
    5. c -> nil
    6. d -> c

+ a -> b -> c -> d -> e
    1. for 1
    2. a -> d
    3. b -> a
    4. for 2
    5. c -> e
    6. d -> c

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {

    if head == nil || head.Next == nil {
        return head
    }

    tempNode := head
    result := head.Next

    for {
        if tempNode == nil || tempNode.Next == nil {
            break
        }
        tempNodeL := tempNode
        tempNodeR := tempNode.Next
        tempNode = tempNodeR.Next
        tempNodeR.Next = tempNodeL
        if tempNode == nil || tempNode.Next == nil {
            tempNodeL.Next = tempNode
        } else {
            tempNodeL.Next = tempNode.Next
        }
    }


    return result
}
```