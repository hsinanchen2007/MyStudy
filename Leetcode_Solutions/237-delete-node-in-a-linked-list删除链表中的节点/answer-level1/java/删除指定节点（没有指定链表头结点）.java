### 解题思路
方法：直接删除指定节点。时间复杂度：O(1)；空间复杂度：O(1)。
![桌面.PNG](https://pic.leetcode-cn.com/f5f87f31fd0a2c1d137b9efacbf922b5575fab63000778908c677afdb3b5153b-%E6%A1%8C%E9%9D%A2.PNG)

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
        //由于没有给定该链表的头结点，因此只能从node向后看，题目中已经说定不包括末尾节点
        //删除node即通过将后面的值赋给node，然后更改node的指针指向下下一个结点即可
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```