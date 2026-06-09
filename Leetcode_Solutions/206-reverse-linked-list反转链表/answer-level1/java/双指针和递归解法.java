### 解题思路
两种方法：
解法一：双指针，较简单（先掌握）
解法二：递归，有点难理解（慢慢理解）

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
// 双指针法
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode temp = null;
        while(cur != null){
            temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
}

//递归解法：
// class Solution {
//     public ListNode reverseList(ListNode head) {
//         if(head == null || head.next == null){
//             return head;
//         }
//         ListNode cur = reverseList(head.next);

//         head.next.next = head;
//         head.next = null;
//         return cur;
//     }
// }

```