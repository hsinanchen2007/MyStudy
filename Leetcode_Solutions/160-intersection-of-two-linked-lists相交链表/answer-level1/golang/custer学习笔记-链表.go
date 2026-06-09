### 解题思路 - 计算链表长度
两个链表各自遍历一次后，

- 我们可以得到它们各自的长度，然后使用游标p和q分别指向两个链表。
- 游标q指向较长的链表，因此先让它移动两个链表长度之差，
- 这时候p和q再一起向前移动，当它们相等时返回它们指向的节点即可。

这种方法的时间复杂度是O(m+n)，空间复杂度是O(1)。

这种方法要先求出两个链表的长度，再对比它们的长度，把较长的链表先走一段。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 计算链表长度 Time: O(m+n), Space: O(1)
func getIntersectionNode(headA, headB *ListNode) *ListNode {
  lenA, lenB := 0, 0 // 首先初始化两个链表长度都为0
  // 遍历两个链表求它们的长度
  for p := headA; p != nil; p = p.Next {
    lenA++
  }
  for p := headB; p != nil; p = p.Next {
    lenB++
  }
  // 接着定义游标p和q分别指向两个链表
  p, q := headA, headB
  if lenA > lenB { // 如果链表A比较长
    for i := 0; i < lenA-lenB; i++ {
      p = p.Next // 就让游标p先移动链表长度之差
    }
  } else {
    for i := 0; i < lenB-lenA; i++ {
      q = q.Next // 否则让q先移动链表长度之差
    }
  }
  // 接下来只要p和q不相等就一起移动
  for p != q {
    p = p.Next
    q = q.Next
  }
  return p // 最后返回p即可
}
```

### 解题思路 - 不计算链表长度
不求链表长度，可以达到相同的效果，求链表的长度，本质上是求它们的差，

并让较长的链表先走一段这个差值，为了达到这个目的，

- 我们同样使用p和q分别指向两个链表，并且一同向前移动
- 如果p先走完指向null，这时我们让p跳到另一条链表，
- q继续移动，如果q也指向null，接着我们也让q跳到另一条链表
- 这个时候可以发现p和q到各自链表结尾的长度一样，
- 他们只要继续移动，就会在第一个相交点相遇。

这种方法的时间复杂度也是O(m+n)。空间复杂度是O(1)。

不过巧妙的避开了对链表长度的计算。代码写起来会更短更统一一些。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 不计算链表长度 Time: O(m+n), Space: O(1)
func getIntersectionNode(headA, headB *ListNode) *ListNode {
  // 边界情况，如果其中一条链表为空，返回空链表即可
  if headA == nil || headB == nil {
    return nil
  }
  // 否则定义游标p和q分别指向两个链表
  p, q := headA, headB
  // 当p和q不相等时执行以下操作
  for p != q {
    if p == nil { // 如果p为空
      p = headB // 就跳转到另一条链表的表头
    } else {
      p = p.Next // 否则p向前移动一个节点
    }
    // 类似的使用同样的方法处理q
    if q == nil { // 如果q为空
      q = headA // 就跳转到另一条链表的表头
    } else {
      q = q.Next // 否则p向前移动一个节点
    }
  }
  // 循环结束后p和q要么指向相交节点，要么都指向空
  return p // 因此只要返回p即可。
}
```