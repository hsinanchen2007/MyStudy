# 环形链表入口节点

## 题目描述

![](https://pic.leetcode-cn.com/8967873351d91e4b0d1c44b9a67663cbe650b17a1b25f1a49568b675ab2a0dca.png)



## 思路分析：判断是否有环

本题是**判断环形链表是否有环**的进阶题目。

环形链表题目利用了**双指针技巧**，设置快慢两个指针，每次快指针走两步慢指针走一步。假如链表有环，那么快慢指针在环的部分终究会相遇。

判断链表是否有环，比较简单直接上代码。

```java
public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
```



## 思路分析：如何找出入口节点？

方便分析作图如下，假设a是链表头节点，b是链表中环的入口节点，c是快慢指针相遇的节点。

三段路径长度按顺时针分别称为ab，bc，cb。链表中环长度为s = bc + cb。

![](https://pic.leetcode-cn.com/d943c1be76b464b26eb30c21bf8e90555ac75297e585cea90c942c1b693f9785.png)

我们需要计算，在c点相遇的时候，快慢指针分别走了多远？利用快慢指针长度的两倍关系去求解问题。

快指针到c点走过的长度 **s1 =  ab + bc + n * s = ab + bc + n * (bc + cb)**

快指针走的距离包括ab+bc的距离，再加上在圆环中环绕圈数的距离。

那么慢指针的长度如何计算？他在环中也走了多少圈？

 这就需要理解一个概念：

> **从慢指针进入环时，到快慢指针相遇，慢指针走过的距离是一定小于等于环的大小。（如果整个链表是一个环，则慢指针走过距离等于环大小）**
> 慢指针进入环后，可以看成快指针在后面追赶慢指针。
>
> - 最好情况快指针就在b的左侧，移动一步两者便相遇。
> - 最差情况为快指针在b的右侧，需要多绕不到一圈的距离。
>
> 分析最差情况：假设慢指针走了一整圈环，回到b点时快指针才追上，慢指针移动长度为s，快指针移动长度则为2s-1。但实际上快指针速度是慢指针两倍，即实际应走距离为2s。可以反证出在慢指针走完一圈之前，快指针必然追上慢指针。

理解了上述概念，可以很快得出，慢指针长度 **s2 = ab + bc**

已知了快指针是慢指针两倍，即  2 *(ab + bc)  = ab + bc + n * (bc + cb) 

推出：**ab = (n-1) * (bc + cb) + cb** 

含义为：**链表头到环入口的距离=相遇点到环入口的距离+（n-1）圈环长度**

分析到这里，其实已经得出答案了。两个链表相遇后，一个指针指向相遇的位置，一个指针指到链表的头节点。两个指针均向后移动，判断当两者相同时，该节点便是链表到环的入口节点。

代码参考：

```java
 public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }

        // 步骤一：使用快慢指针判断链表是否有环
        ListNode fast = head;
        ListNode slow = head;
        boolean hasCycle = false;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // 步骤二：若有环，找到入环开始的节点
        if (hasCycle) {
            ListNode cur = head;
            while (slow != cur) {
                cur = cur.next;
                slow = slow.next;
            }
            return slow;
        }

        return null;
    }
```



