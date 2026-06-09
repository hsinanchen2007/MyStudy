### 解题思路
此处撰写解题思路
1->2->3->4
列表两两交换结果为：
2->1->4->3
(1)那么我们先确定终止递归的条件：
链表为空或者剩余只有一个节点
(2)交换相邻的两个节点：
ListNode first = head;
ListNode second = head.next;
ListNode third = head.next.next;
此处声明三个变量记录交换之前的元素，保证逻辑更清楚
进行交换：
head = second;
head.next = first;
first.next = swapPairs(third);
注意：Head指向第二个元素，然后更新head的next指向第一个元素，再更新fisrt的next指向第三个元素；第三个元素依赖递归函数返回的结果

时间复杂度为哦O(n)，空间负责度为O（1）
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
        if (head == null || head.next == null){
            return head;
        }
        ListNode first = head;
        ListNode second = head.next;
        ListNode third = head.next.next;
        head = second;
        head.next = first;
        first.next = swapPairs(third);
        return head;
    }
}
```