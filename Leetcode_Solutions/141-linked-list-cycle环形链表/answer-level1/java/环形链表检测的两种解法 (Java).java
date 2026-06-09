这道题比较简单，首先我们先来分析一下题目：

环形链表，即原本末尾的节点的 `next` 指针，指向了链表的任意一个节点，形成了一个闭环。在这种环形链表中，遍历时会停不下来，因为在环中会一直循环，这是它的特点。

如果对于哈希表熟悉的话，我们很容易能想到通过哈希表来存储已经遍历的节点，然后判断下个要遍历的节点是否已经在哈希表里存在：若存在则说明是环，否则直到遍历结束也没有找到，那说明不是环。

**解法1：通过哈希表存储判断**

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
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;
        // HashSet用于存储遍历过的节点
        HashSet<ListNode> set = new HashSet<>();
        ListNode cur = head;
        while (cur.next != null) {
            if (!set.add(cur)) {
                return true;
            }
            cur = cur.next;
        }
        return false;
    }
}
```

这个方法优点是比较直观容易，时间复杂度为 `O(n)`，缺点是耗内存，其空间复杂度也是 `O(n)`，毕竟要存储遍历过的节点。

那有没有更好的解法呢？想一想，学校的运动会有长跑项目吧，跑得快的运动员，总会追上跑得慢的运动员，因为他们处于一个圆形跑道里。那么受此启发，我们可以将其应用于这道题目中。

设置两个指针，一个每次走一步，另一个每次走两步，分别称之为快、慢指针。如果快慢两个指针在一个环形链表里，那么快指针一定会追上慢指针，否则快指针会先走到链表尾部，说明没有环存在。

**解法2：通过快慢指针是否会相遇来判断**

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
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;
        // 慢指针
        ListNode slow = head;
        // 快指针
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            // 慢指针每次走一步
        	slow = slow.next;
            // 快指针每次走两步
        	fast = fast.next.next;
            // 当快慢指针相同时，则说明是在圆环里面
        	if (slow == fast) {
        		return true;
        	}
        }
        return false;
    }
}
```

这个方法的时间复杂度为 `O(n)`，空间复杂度为 `O(1)`，是比较高效的解法。

