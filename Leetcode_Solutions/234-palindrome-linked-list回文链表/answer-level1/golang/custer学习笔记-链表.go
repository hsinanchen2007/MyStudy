### 解题思路 - 使用辅助栈
简单的方法是使用辅助栈

遍历链表时，将节点上的数字压栈，链表遍历结束后，出栈，数字的顺序就是链表逆着读的顺序。

比如链表 4 -> 2，压栈   

| (2) | 
| (4) | 

接着遍历一遍单链表，同时将栈中的数字依次出栈做对比。校验是否为回文数字。

此时单链表当前节点的数字是4，辅助栈出栈当前数字是2，不是回文数字。为false

这种方法，遍历两次单链表。时间复杂度O(n),使用辅助栈存储相同规模的数据，空间复杂度也是O(n)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 使用辅助栈 Time: O(n), Space: O(n)
func isPalindrome(head *ListNode) bool {
   stack := make([]int, 0) // 定义一个存储整数的栈
   for p := head; p != nil; p = p.Next { // 遍历单链表
      stack = append(stack, p.Val) // 把数字入栈
   }

   for p := head; p != nil; p = p.Next { // 遍历单链表
      // 对比链表当前节点的数和栈顶的数
      val := stack[len(stack)-1]
      stack = stack[:len(stack)-1]
      if p.Val != val { // 如果不相等
         return false // 则返回false
      }
   }
   return true // 循环结束后没有返回false则返回true
}
```

### 解题思路 - 反转链表
不使用额外的辅助栈，单链表的经典题目 [61.旋转链表](https://leetcode-cn.com/problems/rotate-list/solution/custerxue-xi-bi-ji-lian-biao-by-custergo-3/)

比如链表 4 -> 2 -> 2 -> 4，反转一半的链表，

需要一个cur指向当前节点，一个pre指向前一节点。

反转一半的单链表之后，cur和pre分别向两端移动，对比两边的数字是否相等即可。

如果链表长度是奇数，比如 4 -> 2 -> 1 -> 2 -> 4，

这时cur和pre分别移动到一半长度时，cur指向1，pre指向2，

这个时候正中间的1是不需要和其他对比的。

因此将cur向后移动一位再进行对比即可。

这种方法时间复杂度是O(n),没有使用额外的存储空间，所以空间复杂度是O(1)


![1.png](https://pic.leetcode-cn.com/bcc1dd99c89bbad81ec59b1d1eef81ce0b0521b9e2517d39eed92055fd58b810-1.png)


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 翻转一半链表的方法 Time: O(n), Space: O(1)
func isPalindrome(head *ListNode) bool {
   length := 0 // 定义链表长度为0
   for p := head; p != nil; p = p.Next {
      length++ // 遍历链表，当p不为空时长度+1
   }

   cur := head       // 定义指向当前节点的cur
   var pre *ListNode // 定义前一节点的pre
   for i := 0; i < length/2; i++ {
      next := cur.Next // 先存储cur的下一节点
      cur.Next = pre   // cur指向它的前一节点pre
      pre = cur        // 更新cur和pre的指向，pre移动到cur的位置
      cur = next       // cur移动到next的位置
   }

   if length%2 == 1 { // 判断链表长度是否为奇数
      cur = cur.Next // 是的话，cur还要向后再移动一位
   }
   // pre和cur各自向两边移动
   for ; pre != nil && cur != nil; pre, cur = pre.Next, cur.Next {
      if pre.Val != cur.Val { // 当它们指向的节点不相等时
         return false // 直接返回false,说明并不是回文链表
      }
   }
   return true // 循环结束后还没返回，则最后返回true
}
```