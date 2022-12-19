### 解题思路
此处撰写解题思路
大部分人最难理解就是指针为什么必定相交在环入口

设环到入口的距离是x,环长为L,从入口到交点的距离为p
那么可以得到 
2(x+nl+p)=x+ml+p;
x=(m-2n)*l-p;
现在观察这个式子.
左边：表示从起点到环入口的距离
右边：p走(m-2n)圈表示还在在原地，原地回退p的距离，就是入口，也是就表示(m-2n)*l-p 也是在入口，
联系起来看，从起点走到环入口的距离X，等于p点走(m-2n)L-P的距离，而正好位置都是入口
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
 /**
  public class Solution {
      public ListNode detectCycle(ListNode head) {
            if (head == null || head.next == null || head.next.next == null) return null;
            ListNode fast = head;
            ListNode slow = head;
            while (fast != null && fast.next != null) {
                fast = fast.next.next;
                slow = slow.next;
                if(fast==slow)break;
            }
            if (fast != slow) return null;
            fast=head;
            while (fast != slow) {
                fast = fast.next;
                slow = slow.next;
            }
            return fast;

        }
    }
```