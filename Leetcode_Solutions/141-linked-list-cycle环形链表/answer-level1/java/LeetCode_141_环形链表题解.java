### 解题思路

看了评论区的各种代码，目前我知道的解法有三种：

- 把遍历过的节点缓存出来，如果在遍历过程中，下一个节点完全与当前节点相同，则返回true。如果遍历完都没有相同的节点则返回false。

- 在遍历节点的过程中修改节点的值（这个值越奇怪越好），如果在遍历的过程中第二次发现了这个值，就说明有环，返回true，否则返回false。(最快解法)

- 快慢指针，定义两个指针，一个指针每次走一个next，一个指针每次走多个next，如果两个指针相遇，则说明有环，返回true。否则返回false

### 代码

#### 解法1：缓存遍历过的值

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

        ListNode tmpNode = head;

        List<ListNode> cacheList = new ArrayList<>();
        while (tmpNode != null && !cacheList.contains(tmpNode)) {
            cacheList.add(tmpNode);
            tmpNode = tmpNode.next;
        }

        if (tmpNode == null) return false;
        return true;
    }
}
```

#### 解法2：修改遍历过程中结点的值

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        while (head != null) {
            if (head.val != Integer.MIN_VALUE) {
                head.val = Integer.MIN_VALUE;
            } else {
                return true;
            }
            head = head.next;
        }
        return false;
    }
}
```

#### 解法3：快慢指针(未通过测试用例[1, 2], -1)

```java
if (head == null) return false;
        ListNode fast = head;
        ListNode slow = head;
        while (!fast.equals(slow) && (slow != null || fast.next != null)) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return !(slow == null || fast.next == null);
```

