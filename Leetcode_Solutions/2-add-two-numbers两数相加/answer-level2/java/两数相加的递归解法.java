### 解题思路
![image.png](https://pic.leetcode-cn.com/3cd44777dfb666a27351f9da0323a838f5e4b5a428efb583889cd494db769e51-image.png)

题目没有限制栈的深度，因此我选用最简单的递归来完成。

递归的两个基本法则是：**1.基准情况；2.不断推进。**

加法就是：**低位相加，溢出进位。**

题目给出的链表是 **逆序** 的方式，那么先计算第一个节点的和，如果和有溢出，就把这个值交给下一个节点。

发生溢出的时候：
- 如果第一个节点有效，它的下一个节点：
  - 有效，直接相加。
  - 无效，先尝试用第二个节点的下一个节点，如有效则相加，否则只能 new 节点并包含溢出的数。
- 如果第一个节点无效，那么第二个节点必定存在，它的下一个节点：
  - 有效，直接相加。
  - 无效，new 节点并包含溢出的数。

以目前的虚拟机参数来看，栈深度基本够用，所以只要写好递归的两个基本法则，通常是没毛病的。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      if (l1 == null && l2 == null) {
        return null;
      }
      int sum;
      ListNode t1 = null, t2 = null;
      if (l1 == null) {
        sum = l2.val;
        t2 = l2.next;
      } else if (l2 == null) {
        sum = l1.val;
        t1 = l1.next;
      } else {
        sum = l1.val + l2.val;
        t1 = l1.next;
        t2 = l2.next;
      }
      ListNode result = new ListNode(sum);
      int i = sum / 10;
      if (i > 0) {
        result.val %= 10;
        if (t1 != null) {
          t1.val += i;
        } else if (t2 != null) {
          t2.val += i;
        } else {
          t1 = new ListNode(i);
        }
      }
      result.next = addTwoNumbers(t1, t2);
      return result;
    }
}
```