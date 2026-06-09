### 解题思路
与旋转数组相同，旋转链表的思路是：

> 单链表带有Next指针这个特点，让我们可以把链表头尾连接起来。

- 题目要求操作k次，把链表右边的节点旋转到左边，当k大于链表长度时这个操作会重复循环，
- 所以可以先把k更新为对n(链表长度)取模后的结果。k = k % n (避免无用的重复操作)。

1. 接下来，从链表原来的头节点出发，遍历到前n-k个节点中的最后一个节点。
2. 作为新的结束节点，下一个节点作为新的头节点。
3. 把新的结束节点指向空nil。返回新的头节点即可。

这种方法需要遍历两次链表，一次找到链表长度，一次找到链表分割点。

因此时间复杂度是:O(n)，不需要额外的存储空间，空间复杂度是:O(1)。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// Time: O(n) Space: O(1)
func rotateRight(head *ListNode, k int) *ListNode {
   // 处理边界情况，链表为空，或只有一个节点，或k<=0
   if head == nil || head.Next == nil || k <= 0 {
      return head // 直接返回原链表
   }
   end := head // 否者定义指向链表结束节点的指针end
   n := 1 // 定义链表长度n
   for end.Next != nil { // 遍历一次链表计算链表长度
      n++
      end = end.Next
   }
   // 然后让end的Next指向头节点，形成一个环形链表
   end.Next = head

   k %= n         // 把k更新为对n取模的结果
   newEnd := head // 定义newEnd指针
   for i := 0; i < n-k-1; i++ {
      newEnd = newEnd.Next // 遍历n-k-1后，指向新的结束节点
   }
   newHead := newEnd.Next // newEnd的下一个节点，作为链表新的头节点
   newEnd.Next = nil      // newEnd的Next指针置空nil
   return newHead         // 最后返回新的头节点
}
```