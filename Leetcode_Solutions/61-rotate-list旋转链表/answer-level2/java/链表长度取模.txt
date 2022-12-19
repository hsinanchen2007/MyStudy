### 解题思路
此处撰写解题思路
找到链表长度对k取模后，再算

```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
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
 public static ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        // ListNode head = new ListNode(1);
        ListNode curNode = head;
        int length = 0;
        while (curNode != null) {
            length++;
            curNode = curNode.next;
        }
        int pos = k % length;
        if (pos == 0) {
            return head;
        }
        // zhao lenth-k
        curNode = head;
        ListNode newHead = null;
        ListNode newTail = null;
        ListNode tail = null;
        int i = 0;
        while (curNode != null) {

            if (i == length - pos - 1) {
                newTail = curNode;
                newHead = curNode.next;

            }
            if (i == length - 1) {
                tail = curNode;
            }
            curNode = curNode.next;
            i++;
        }
        newTail.next = null;
        tail.next = head;
        return newHead;
    }
}
```