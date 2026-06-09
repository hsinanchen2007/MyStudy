### 解题思路
1. 迭代法
    a) 对于迭代法，首先考虑特殊情况。
        i) 单链表有至少一个为空
    b) 首先建立一个前序指针prehead，比较容易在算法结束时返回合并得到的新链表。
    c) 维护一个pre指针，用来不断调整其next节点。
    d) 将l1和l2的两个指针分别指向两个有序链表。
        i) 如果l1的节点小于l2的节点，则应该将l1.next指向l2所在节点。然后令l2指向下一个节点。
        ii) 如果l1的节点大于等于l2的节点，则将l2.next指向l1所在节点。然后令l1指向下一个节点。
        iii) 每次操作(i)或者(ii)的操作过后，都令pre指向下一个节点。
    e) 重复d)的操作，直至l1或者l2的值为null。然后返回p指针re。
2. 递归法(递归法的本质就是函数在运行的时调用自己)
    a) 终止条件：当两个链表都为空时，表示我们对链表已合并完成。
    b) 如何递归：我们判断 l1 和 l2 头结点哪个更小，然后较小结点的 next 指针指向其余结点的合并结果。（调用递归）
[note]递归方法必须要有终止条件！！！
      递归函数不断调用自己，直至遇到终止条件后进行回溯，最终返回答案。
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
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead = new ListNode(-1);

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        // exactly one of l1 and l2 can be non-null at this point, so connect
        // the non-null list to the end of the merged list.
        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
    }
}


```
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
        else if (l2 == null) {
            return l1;
        }
        else if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
        else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }

    }
}

```