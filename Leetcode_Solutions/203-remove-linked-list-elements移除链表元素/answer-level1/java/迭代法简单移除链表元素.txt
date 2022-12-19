### 解题思路
方法：迭代法
思路：
1. 删除第一元素直接head = head.next 。
2. 删除中间元素，就需要记录要删除节点的前一个节点，需要两个指针，pre.next = cur.next;


[个人博客地址](http://47.101.136.180/)

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
    public ListNode removeElements(ListNode head, int val) {
        
        //判断起始元素是否要删除
        while (head != null && head.val == val) {
            head = head.next; //直接头指针后移
        }

        //定义两个指针用于删除中间元素
        ListNode pre = null;
        ListNode cur = head;

        while(cur != null) {
            if (cur.val == val) {
                pre.next = cur.next;
            } else {
                pre = cur;
            }
            cur = cur.next;
        }
        return head;
    }
}
```