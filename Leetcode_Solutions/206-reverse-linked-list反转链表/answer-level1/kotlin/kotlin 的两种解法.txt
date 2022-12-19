### 解题思路

迭代解法的核心在于不断对每个结点的指向关系进行调整：

1. 使用临时变量缓存原先的后继结点
2. 原先的先驱结点时调整后的后继，即 `prev` 变为 `curr.next`
3. 接着处理原先的后继结点

递归解法的核心在于构建递推关系：
1. 想求链表 L(n) = a1-> a2 -> ... -> an 的反转结果，就是在 a2 -> ... ->an 的反转链表末尾加上 a1 即可
2. 步骤 1 中要求的链表末尾，实际就是 a1 的 next

### 代码

迭代解法：

```kotlin
class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        var prev: ListNode? = null
        var curr = head
        while (curr != null) {
            val temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        }
        return prev
    }
}
```

递归解法：

```kotlin
class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        if (head == null) return null
        if (head.next == null) return head

        val next = head.next
        head.next = null
        val newHead = reverseList(next)
        next!!.next = head
        return newHead
    }
}
```