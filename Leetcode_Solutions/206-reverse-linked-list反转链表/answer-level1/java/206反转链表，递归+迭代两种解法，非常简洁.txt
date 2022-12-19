### 解题思路
此处撰写解题思路

方法一，用递归解决，这是《剑指offer》上面的思考提升部分但其实是更好想到的。新定义一个newHeader，在一开始通过递归深入到链表末尾之后，它其实就不会变化了，最后直接返回它即可。

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        // 方法一，递归
        if(head == null || head.next == null) return head;
        // 一口气深入到链表末尾，然后以这个末尾作为新的链表头
        ListNode newHeader = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHeader;
    }
}
```

方法二，迭代，总共需要新定义三个ListNode变量，而且temp每次都要刷新位置。

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        // 方法二，迭代
        // 总共需要新定义三个ListNode变量
        ListNode newHeader = null;
        ListNode currNode = head;
        while(currNode != null) {
            ListNode temp =  currNode.next;
            currNode.next = newHeader;
            newHeader = currNode;
            currNode = temp;
        }
        return newHeader;
    }
}
```