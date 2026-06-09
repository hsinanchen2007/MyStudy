![图片.png](https://pic.leetcode-cn.com/9218afb6becfff5a6408c7a831c80239fd33f4cc1a8348fafe0017cb30d85c8b-%E5%9B%BE%E7%89%87.png)

### 解题思路
从中间将原来的链表切成连段，左边已经是反转好的，右边待反转。用`newHead`表示反转好的链表头，`curHead`是右边待反转的链表的当前位置，只需要`curHead`结点指向`newHead`即可完成反转，同时两个节点都向后移动。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x;  }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        //循环
        ListNode newHead = null; //反转后的链表头
        ListNode curHead = head;

        //特殊情况，无结点和一个结点
        while(curHead!=null){
            ListNode next = curHead.next; //保存下一个结点
            curHead.next = newHead; // 当前结点指向前一个结点
            //连个结点都向后一一位
            newHead = curHead;
            curHead = next;
        }
        return newHead;
    }
}
```