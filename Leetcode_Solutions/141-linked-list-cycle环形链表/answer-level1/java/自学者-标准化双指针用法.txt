### 解题思路
等待进一步的梳理快慢双指针，先记录一下
* 双指针的概念
  初始：慢指针初始指向head，快指针初始指向head
* 慢指针步进1步：slow = slow.next;
* 快指针步进2步： fast = fast.next.next
* 循环判定条件以fast快指针为判断依据，函数中间做出口控制。

### 踩坑过程
* 快慢指针一般都初始化指向链表的头结点head，参考其他学友的快指针直接指向head.next，容易造成思维不统一
* 经典快慢指针用法是用快指针作为循环结束判断条件，但是其他学友的判断结束条件
* 题目中说输入一个pos值，还有链表中的val是这道题非常迷惑的地方，容易卡壳

经典环判断算法代码示例：
### 代码
```java
boolean hasCycle(ListNode head) {
    ListNode fast = head;
    ListNode slow = head;
    
    while(fast != null && fast.next != null) {
        // 快指针步进两步
        fast = fast.next.next;
        // 慢指针步进一步
        slow = slow.next;
        // 判断快指针是否碰到了走的慢的慢指针，碰到了则形成环路
        if (fast == slow) {
            return true;
        }
    }

    // 没有碰到慢指针，表示链表结束了，不会有环路出现
    return false;
}
```

### 参考其他解题代码-容易被初始条件和退出条件搞混，不推荐

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
public class Solution {
    public boolean hasCycle(ListNode head) {
       // 单节点直接返回非环
       if(head == null || head.next == null) {
           return false;
       }
       ListNode slow = head;
       // 方便双节点判断
       ListNode fast = head.next;
       
       while(fast != slow) {
          //第一个节点与下一个节点判断之后，继续判断快指针的下一个节点完成首次判断
          if(fast == null || fast.next == null) {
              return false;
          }
          // 步进一步
          slow = slow.next;
          // 步进两步，[3,2,0,-4]
          //step1. slow = 3, fast = 2
          //step2. slow = 2, fast = -4, 中间没有判断0，直接移动两步到了-4，
          // fast!=null && fast.next != null
          fast = fast.next.next;
       }          
       return true;
    }
}
```