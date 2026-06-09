### 解题思路
大概思路就是走到尾节点的时候让中间节点走到一半，也就是尾节点走两步，中间节点走一步。
没想到打败了100%的用户哈哈
![image.png](https://pic.leetcode-cn.com/673e21ab910df92a25f086bd56765163ff77a1b9d9af90a9db68cb49073d68bf-image.png)


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
    public ListNode middleNode(ListNode head) {
        // 创建一个节点，每次往前两步，另一个节点每次往前一步
        ListNode end = head;
        ListNode middle = head;
        if (end.next == null) {
            return middle;
        }

        while (end != null) {
            // 步进两步，如果第二步为null了，则退出。如果最后结果为null了，也正常退出。
            if ((end = end.next) != null) {
                end = end.next;
            } else {
                return middle;
            } 
            middle = middle.next;
        }

        return middle;
    }
}
```