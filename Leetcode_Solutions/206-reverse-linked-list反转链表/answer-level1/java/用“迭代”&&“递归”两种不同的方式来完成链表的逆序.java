### 解题思路
链表逆序是面试后中比较常规的一道简单的数据结构算法面试题，一般任选“迭代”或者“递归”实现都可以，如果对面试官说，自己可以将两种实现都写出来，那想必一定很加分，下面我就用这两种方法分别来实现。

### 代码
（1）递归代码
先通过递归的方式取到最后一个链表节点，然后将其指向为前一个节点，然后在一层的递归中均完成这里所描述的步骤；
时间复杂度：O(n),假设 n 是列表的长度，那么时间复杂度为 O(n)；
空间复杂度：O(n),由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n层；

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

    public ListNode reverseList(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode node = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        
        return node;
    }
}

```

### 代码
(2)使用一个前驱指针和当前指针的迭代遍历算法实现, 每次通过pre前驱指针保存逆序后的前一个节点，而当前cur指针用于继续向后遍历;
时间复杂度：O(n),假设 n 是列表的长度，那么时间复杂度为 O(n)；
空间复杂度：O(1), 因为使用两个指针, 所以空间的开销即为O(1)；

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

public ListNode reverseList(ListNode head) {

        if(head == null) {
            return null;
        }

        ListNode pre = null;
        ListNode ptr = head;
        while (ptr != null) {
            ListNode temp = ptr.next;
            ptr.next = pre;
            pre = ptr;
            ptr = temp;
        }
        ptr =  pre;
        return ptr;
}
```