### 解题思路
前几天做到一道题：[19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)
感觉思路可以借鉴一下。

19题有个题解中使用了一个巧妙的处理方法：**在head节点前面增加一个d节点**，让快指针 *fast* 和慢指针 *slow* 初始化时都指向d节点。这样做有个好处,就是可以避免空指针问题。（不信自己去试一下）


这道题的思路是这样：定义快慢两个指针 *fast* 和 *slow*。让他们都指向d。
然后进行循环以遍历链表。遍历的过程中：**fast指针每次走两步，slow指针每次走一步**。
按照题目要求，如果有两个中间节点，则返回第二个中间节点，所以这样处理是没问题的。

如果链表为奇数的话，在最后一步，**fast指针只走一步，slow指针也只走一步**。

这样子在循环的每一轮中，slow都指向了fast的一半的位置。


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        
        ListNode d=new ListNode(0);
        d.next=head;
        ListNode fast=d;
        ListNode slow=d;
        while(fast!=null)
        {
            fast=fast.next;
            if(fast!=null)
            {
                fast=fast.next;
            }
            slow=slow.next;
        }
        return slow;
    }
}
```

时间复杂度就是 *O(n)*,因为只遍历一次链表。
空间复杂度 *O(1)*,因为只用到两个指针。


