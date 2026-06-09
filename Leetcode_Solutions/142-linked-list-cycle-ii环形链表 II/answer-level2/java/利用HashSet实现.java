### 解题思路
将遍历过的节点保存起来，查找当前节点是否被保存过，保存过说明此节点就是循环的第一个节点，利用HashSet的元素不可重复特性，有重复元素则会保存失败。

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode curr = head;
        // 利用HashHashSet不能重复的特性，如果添加节点时表示失败，说明之前已经添加过，说明当前节点是循环的第一个节点
        HashSet<ListNode> hashSet = new HashSet<>();
        while (curr != null) {
            if(!hashSet.add(curr)) {
                return curr;
            }
            curr = curr.next;
        }
        return null;
    }
}
```