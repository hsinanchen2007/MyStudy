### 解题思路
此处撰写解题思路
思路：
1、先定义一个指针确定改节点开始的链表长度n（步长是1 ，此处步长可以大点）
2、再用一个指针遍历到 n-k 个位置拿到节点


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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode fast = head;
        int i = 1;
        while(fast != null ){
            fast = fast.next;
            ++i;
        }

        ListNode slow = head;
        int j = 1;
        while(slow != null &&  j< i-k){
            slow = slow.next;
            ++j;
        }
        return slow;
    }
}
```