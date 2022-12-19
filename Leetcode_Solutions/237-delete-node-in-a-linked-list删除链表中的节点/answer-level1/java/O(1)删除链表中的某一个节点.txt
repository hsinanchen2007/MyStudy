### 解题思路
这道题刚写的时候有点纳闷，因为没有给head指针。
查看题解之后，发现只是将待删除节点的val和next替换为下一个节点的值即可。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```