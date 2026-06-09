### 解题思路
//双指针解法：
//一个指针一个移动一次，另一个指针一个移动两位，如果两个相遇则有环
//两个需要注意的点：第一个while循环的终止条件：肯定是三个真，才可以，所以是&&
//第二个：双指针的话，一个移动两次，一个移动一次，所以l2.next.next；

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null) return false;

        ListNode l1=head;
        ListNode l2=head.next;
        while(l1!=null&& l2!=null && l2.next!=null){
           if(l1==l2){
               return true;
           } 
           l1=l1.next;
           l2=l2.next.next;
        }
        return false;
    }
}
//双指针解法：
//一个指针一个移动一次，另一个指针一个移动两位，如果两个相遇则有环
//两个需要注意的点：第一个while循环的终止条件：肯定是三个真，才可以，所以是&&
//第二个：双指针的话，一个移动两次，一个移动一次，所以l2.next.next；

```