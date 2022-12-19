### 解题思路
反转，咱们就一节一节的反转。首先获取第二节点（也就是头节点之后的链表），把头节点指针指向空（这里其实就生成了一个新的链表，只是这个链条目前只有一个节点）。然后获取第三节点，把第二节点指向原来的头节点。然后获取第四节点，把第三节点指向原来的第二节点。。。可以发现，每次反转涉及到的是三个节点，一个是原链表的头节点，一个是原链表的第二节点，一个是新链表的头节点，而原链表的第二节点又能通过原链表的第一节点获得，所以真正需要的就两个节点，一个是原链表的头节点，一个是新链表的头节点。所以，咱们可以写一个方法，让其递归，每次反转一个节点，直到原链表为空。
形象点，可以把链表想成链条，原链表是一个方向向右的链条，新链表是一个方向向左的链条。
如果不理解链表，可以参考下这个图
![链表.png](https://pic.leetcode-cn.com/dc9065e503c41e8a3e0c759b0ffddd4455531f431e3f46cd7cd6a910e4d17b3d-%E9%93%BE%E8%A1%A8.png)
一个ListNode是一个节点，val是这个节点的值，next属性也是一个ListNode，也就是一个节点里面包含另一个节点，就好像指针一样，一个节点指向另一个节点直到指向null。
更准确的说，这是单向链表，还有双向链表。对于单向链表，头节点就相当于是整个链表，而之后的节点都不是完整的链表。比如最后一个节点，它指向空，没办法只通过它获取到链表的其他节点的值。
单向链表添加节点主要是头添加和尾添加，头添加就是让一个节点指向链表的头节点，尾添加则是让尾节点指向一个新的节点（这个新节点可以是指向空的，也可以是一个链表。如果它是一个链表这就是两个链表的结合）。链表也可以从中间添加节点，不过会麻烦一点，这里就不介绍那么多了。
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
    public ListNode reverseList(ListNode head) {
        //提交的测试真是调皮啊，只能先加个空判断
        if (head == null) return null;
        //获取原链表的第二个节点
        ListNode next = head.next;
        //原链表的头节点指针指向空
        head.next = null;
        //递归反转
        return reverse(head, next);
    }
    //形参的名字，我是没想到更好的，左右理解起来还可以
    private ListNode reverse(ListNode left, ListNode right){
        //反转结束，right自然就是null，这时返回left即可
        if (right == null) return left;
        //获取原链表的第二个节点
        ListNode next = right.next;
        //原链表的头节点指针指向反转后的链表的头指针，也就是成为了反转后的链表的新的头指针
        //或者说右链表的头节点加入到左链表并成为了左链表的头节点
        //换个有趣的说法，right叛变了，成为了left，而next是新的right
        right.next = left;
        //递归反转
        return reverse(right, next);
    }
}
```