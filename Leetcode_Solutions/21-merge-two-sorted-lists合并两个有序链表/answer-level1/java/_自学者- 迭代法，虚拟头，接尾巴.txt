### 解题思路
* 增加1个虚拟头，减少循环中的if判断
* 返回的时候返回head->next丢掉第一个元素
* 遗留的尾巴进行直接对接。如果是无序列表，可能要把尾巴排个序再接入进来。

## 踩坑
* 脑袋瓜子混乱的很！！！
* 一开始考虑两个比较，每次步进两步，致命伤。
* 接入的才步进，而不是一次接纳两个

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
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
//        printLink(l1);
//        System.out.printf("\n");
//        printLink(l2);
//        System.out.printf("\n");
        ListNode node1 = l1;
        ListNode node2 = l2;
        ListNode crawlNode = new ListNode(Integer.MAX_VALUE);
        ListNode head = crawlNode;
        while (node1 != null && node2 !=null) {
            if (node1.val <= node2.val) {
                crawlNode.next = node1;
                node1 = node1.next;
            } else {
                crawlNode.next = node2;
                node2 = node2.next;
            }
            //移动到下一个位置
            crawlNode = crawlNode.next;
        }
        crawlNode.next = node1 == null ? node2 : node1;
        return head.next;

    }

    public void printLink(ListNode head) {
        while (head != null) {
            System.out.printf("%d ", head.val);
            head = head.next;
        }
    }
}
```