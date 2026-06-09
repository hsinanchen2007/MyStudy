### 解题思路
此题要自己添加一个头结点。每四个节点看做一组，只翻转中间两个元素。之后更新。如图：
![1582037868233.jpg](https://pic.leetcode-cn.com/8db7944d05b93e57bb3971ab4daf379fbbb562250ef739a9a584e0491dccb39b-1582037868233.jpg)

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
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null)
            return head;
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        ListNode pre = preHead;
        ListNode cur = head;
        ListNode next_cur =null;
        while(cur!=null&&cur.next!=null){
            next_cur = cur.next.next;
            pre.next = cur.next;
            cur.next.next = cur;
            cur.next = next_cur;

            pre = cur;
            cur = next_cur;
        }
        return preHead.next;
    }
}
```