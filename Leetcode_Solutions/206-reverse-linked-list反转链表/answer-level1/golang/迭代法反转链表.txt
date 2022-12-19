### 解题思路
1. 增加前导节点，其Next值用于迭代完成后返回链表头；
2. 每次迭代先暂存head.Next的指向，即本次迭代的要返转为首节点的节点，然后把head.Next指向head.Next.Next，本次首节的Next指向原首节点h.Next
3. h.Next指向暂存节点，即现首节点

h -> **1** -> 2 -> 3 -> 4 -> 5
....**head**

1. tmp = head.Next
tmp -> 2 -> 3 -> 4 -> 5

2. head.Next = head.Next.Next
h -> **1** -> 3 -> 4 -> 5
....**head**

3. head.Next.Next = h.Next
.............**h.Next**
tmp = 2 -> **1** -> 3 -> 4 -> 5
...............**head**

4. h.Next = tmp
h -> 2 -> **1** -> 3 -> 4 -> 5
...........**head**
>>>

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    
    h := &ListNode{
        Next: head,
    }
    
    for head != nil && head.Next != nil {
        tmp := head.Next
        head.Next,head.Next.Next = head.Next.Next,h.Next
        h.Next = tmp
    }
    return h.Next
}
```