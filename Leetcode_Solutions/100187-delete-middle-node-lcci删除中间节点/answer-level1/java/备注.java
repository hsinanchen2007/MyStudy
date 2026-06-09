### 解题思路

单向链表，分别存储值和指针（指向下一个）
1.后一个赋值前一个
2.用后一个指针指向赋值前一个的指针 实现打断


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
import java.util.Scanner;
class Solution {
    public void deleteNode(ListNode node) {
    node.val = node.next.val; 
	node.next = node.next.next;

    }
}
```