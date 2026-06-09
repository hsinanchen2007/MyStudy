### 题目说明
这道题与《剑指offer》有一些不同：
1. 本题中，输入的类型为：`head: ListNode, val: int`，即 `val` 的类型是整形；
2. 在《剑指offer》中，默认输入为 `head: ListNode, val: ListNode`，即 `val` 的类型是链表。

### 1. `val: int` 解法

### 代码
```python []
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)  # 设置伪结点
        dummy.next = head
        if head.val == val: return head.next # 头结点是要删除的点，直接返回
        while head and head.next:
            if head.next.val == val:   # 找到了要删除的结点，删除
                head.next = head.next.next
            head = head.next
        return dummy.next
```

### 复杂度分析
- 时间复杂度：$O(N)$。$N$ 为链表的长度，最坏情况下，要删除的结点位于链表末尾，这时我们需要遍历整个链表。
- 空间复杂度：$O(1)$。仅使用了额外的 `dummy`。

### 2. `val: ListNode` 解法：信息交换法

首先说明，本人第一次接触这个方法，也是比较懵，但是细细想来还觉得有一番道理，这道题其实考察了我们对链表的操作和时间复杂度的理解。如果以下论述有不当之处，恳请各位多多指正。

一般来讲，正常的解法时间复杂度都是 $O(N)$，因为我们要找到待删除节点，不得不牺牲 $O(N)$ 的时间复杂度。那么 $O(1)$ 的时间复杂度是如何实现的呢？这里有一个信息交换法，即：

假如 `head` 为 `4 -> 5 -> 1 -> 9`，`val` 为 `5 -> 1 -> 9`，表示我们要删除结点 5，这时我们使用信息交换，把 `val` 改为 `1 -> 9`的信息就行了。

为什么呢？因为**我们把待删除节点的后一个元素赋值给待删除节点，也就相当于删除了当前元素。**

但是聪明的你一定会举出反例：如果 `val` 的值是最后一个元素 `9` 呢？我们无法找到 `9` 的后一个元素（因为没有），只能重头开始找待删除元素 `9`，这样的话时间复杂度再次变成了 $O(N)$。

这就是这道题目有意思的地方，我们发现，如果删除节点为前面的 $n-1$ 个节点，时间复杂度均为 $O(1)$，只有删除节点为最后一个时，时间复杂度才会变成 $O(n)$。平均时间复杂度为：$(O(1)\times(n-1) + O(n))/n = O(1)$，仍然为 $O(1)$。


### 代码

（以下代码由于题目类型不符无法通过，供参考）




```java []
class deleteNode {public static ListNode deleteNode(ListNode head, ListNode val){
        if (head == null || val == null){
            return null;
        }
        if (val.next != null){   // 待删除节点不是尾节点
            ListNode next = val.next;
            val.val = next.val;
            val.next = next.next;
        } else if (head == val){   // 待删除节点只有一个节点，此节点为头节点
            head = null;
        } else {   // 待删除节点为尾节点
            ListNode cur = head;
            while (cur.next != val){
                cur = cur.next;
            }
            cur.next = null;
        }
        return head;
    }
 
}
```
```python []
class Solution:
    def deleteNode(self, head, val):
        if head is None or val is None:
            return None
        if val.next is not None:  # 待删除节点不是尾节点
            tmp = val.next
            val.val = tmp.val
            val.next = tmp.next
        elif head == val:  # 待删除节点只有一个节点，此节点为头节点
            head = None
        else:
            cur = head    # 待删除节点为尾节点
            while cur.next != val:
                cur = cur.next
            cur.next = None
        return head

```


### 复杂度分析
- 时间复杂度：$O(1)$。平均时间复杂度为：$(O(1)\times(n-1) + O(n))/n = O(1)$，仍然为 $O(1)$。
- 空间复杂度：$O(1)$。

### 相关题目

掌握如上思想，题目 [面试题 02.03. 删除中间节点](https://leetcode-cn.com/problems/delete-middle-node-lcci/) 就变得很简单了😄

欢迎补充 C++ 代码~如有问题，欢迎讨论~