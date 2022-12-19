### 代码

```kotlin
class Solution {
    fun numComponents(head: ListNode?, G: IntArray): Int {
        var node = head
        val list = G.toMutableList()
        var result = 0
        var match = false
        while (node != null){
            while(node != null && list.contains(node.`val`)){
                list.remove(node.`val`)
                match = true
                node = node.next
            }
            result += if (match) 1 else 0
            node = if (node != null) node.next else break
            match = false
        }
        return result
    }
}

```