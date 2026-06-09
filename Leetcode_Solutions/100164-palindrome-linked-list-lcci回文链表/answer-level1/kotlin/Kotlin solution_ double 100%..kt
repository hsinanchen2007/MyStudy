执行用时 : 284 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 : 43.8 MB, 在所有 Kotlin 提交中击败了100.00%的用户

```
    fun isPalindrome(head: ListNode?): Boolean {
        if (head?.next == null) {
            return true
        }
        var p = head
        var count = 0
        while (p != null) {
            count++
            p = p.next
        }
        var half = count / 2
        val list = IntArray(half)
        p = head
        while (half-- > 0) {
            list[half] = p?.`val` ?: 0
            p = p?.next
        }
        if (count and 1 == 1) {
            p = p?.next
        }
        half = 0
        while (half < count / 2) {
            if (p?.`val` != list[half]) {
                return false
            }
            half ++
            p = p.next
        }
        return true
    }
```
