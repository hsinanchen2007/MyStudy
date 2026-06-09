### 解题思路
![2020-03-02_161007.jpg](https://pic.leetcode-cn.com/362652ed5739ef5ecf2ed47a6567bc32323167b4fdf85d8cc231e96f790fd991-2020-03-02_161007.jpg)


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