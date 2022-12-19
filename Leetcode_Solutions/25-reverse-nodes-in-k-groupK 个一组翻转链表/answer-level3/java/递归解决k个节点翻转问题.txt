### 解题思路
此处撰写解题思路
分三步拆解题意:
1 需要判断当前listNode的总长度与k的大小
2 局部翻转采用头插法
3 采用递归的方式来不停的局部翻转

在保证listNode大于k个节点的情况下,前k个节点排好序,那么第k个节点的next就是下一个k个节点排好序的局部列表

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k <= 1) {
            return head;
        }
        if (!hasKElement(head, k)) {
            return head;
        }
        int count = 2;
        ListNode firstNode = head;
        ListNode temp = head.next;
        while (count <= k & temp != null) {
            ListNode next = temp.next;
            temp.next = firstNode;
            firstNode = temp;
            temp = next;
            count++;
        }
        head.next = reverseKGroup(temp, k);  //这里不能做非空判断,否则会成环
        return firstNode;
        
    }

    public boolean hasKElement(ListNode head, int k) {
        if (head == null) {
            return false;
        }

        int size = 0;
        ListNode cursor = head;
        while(cursor != null) {
            size += 1;
            if (size >= k) {
                return true;
            }
            cursor = cursor.next;
        }
        return false;
    }
}
```