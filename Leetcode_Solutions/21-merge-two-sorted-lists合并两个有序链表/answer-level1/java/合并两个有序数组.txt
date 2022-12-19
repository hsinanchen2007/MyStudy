### 解题思路
方法一：递归。时间复杂度：O(n+m)；空间复杂度：O(n+m)。
![递归.PNG](https://pic.leetcode-cn.com/549f2f331c24bafb2fbe9238a92023b366cd8ad503771d7f31f08b55b832459e-%E9%80%92%E5%BD%92.PNG)
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //递归
        if(l1 == null)  return l2;
        else if(l2 == null) return l1;
        else if(l1.val < l2.val){
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }else{
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```
方法二：迭代。时间复杂度：O(n+m)；空间复杂度：O(1)。
![迭代.PNG](https://pic.leetcode-cn.com/8daeee348bbb6961a34566bc2be20d3d49fdcfb6a20b39a52062bfb5de81e9d1-%E8%BF%AD%E4%BB%A3.PNG)
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //迭代
        ListNode head = new ListNode(-1);

        //假的头结点
        ListNode prev = head;

        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                prev.next = l1;
                l1 = l1.next;
            }else{
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        //特殊情况：比如某个链表已经为空
        prev.next = l1 == null ? l2 : l1;

        return head.next;
    }
}
```
