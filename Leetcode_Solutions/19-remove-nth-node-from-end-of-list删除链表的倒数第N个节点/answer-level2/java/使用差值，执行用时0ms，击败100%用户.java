![2020-03-04_220406.jpg](https://pic.leetcode-cn.com/3a8324b3dce70a345e4e1034d10c216e40a6031ddb2b99ab0ed9af465876cde6-2020-03-04_220406.jpg)

### 解题思路
1.拿到链表之后，首先通过一次循环拿到链表的长度count。
2.由于链表首节点可以理解为是第零个元素，知道总长度count，所以删除倒数第n个元素就是删除从前往后第count - n - 1个元素。
3.最后判断n是否为1或者不为1,为1的话说明删除的是最后一个元素。
### 复杂度分析
时间复杂度：O(N)
空间复杂度：O(1)

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null) return null;
        ListNode temp = head;
        int count = 0; // 链表有多少个节点
        while(temp!=null) {
            count++;
            temp = temp.next;
        }
        // 删除的是头结点
        if(count == n) return head.next;
        temp = head;
        for (int i = 0; i < count - n - 1; i++) {
            temp = temp.next;
        }
        // 此时temp是待删除元素的上一个元素
        if(n == 1) {
            temp.next = null;
        }else {
            temp.next = temp.next.next;
        }
        return head;
    }
}
```