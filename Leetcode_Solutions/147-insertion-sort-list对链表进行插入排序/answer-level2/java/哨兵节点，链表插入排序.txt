### 解题思路
设置哨兵节点，每一次查找，都从头开始。
优化：记录排好序的尾节点，当前节点先和尾节点进行比较，若比尾节点值大，说明当前节点无需排序，可直接进入下一节点插入排序。

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
    public ListNode insertionSortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        //哨兵节点
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = head;
        //当前位置
        ListNode cur = head;
        //排好序的尾节点
        ListNode tail = head;
        while(cur != null){
            //进行下一轮排序，尾节点向前移动
            if(tail.val < cur.val){
                tail.next = cur;
                tail = cur;
                cur = cur.next;
            }
            //从头开始查找插入位置
            else{
                ListNode tmp = cur.next;
                tail.next = tmp;
                ListNode pre = dummy;
                //计算插入位置，即为pre的下一个
                while(pre != null && pre.next.val < cur.val){
                    pre = pre.next;
                }
                //插入当前节点
                cur.next = pre.next;
                pre.next = cur;
                //进行下一轮比较
                cur = tmp;
            }
        }
        return dummy.next;
    }
}
```