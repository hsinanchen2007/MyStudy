## 思路:

这道题难点,就是如何找到那个旋转点?

比如示例1,`1->2->3->4->5->NULL, k = 2` ,我们要找到`3`这个值,只要把它下一位为空,将下面一段链表和它这段链表连接起来就行了!


![Snipaste_2019-05-23_15-15-28.png](https://pic.leetcode-cn.com/d75db4d5b9b5b69d80114c2af31dcdcc4a18539ade0255251869253363dbe79e-Snipaste_2019-05-23_15-15-28.png)

按照题目的意思是向右移动`2位`,换句话说, 以`3`作为链表头,把它前面的链表连在它后面!现在问题就是如何找`3`,我们发现`链表的个数-k`就是从链表头到`3`位置.

还有一个问题,就是如果`k = 6`其实就是相等于`k=1`;所以我们要防止循环.

问题变成了,1. 求链表长度;2. 找 `num - num % k`的位置

代码1 没有借用`dummy`,相对于代码2 更容易理解一点!

## 代码:

代码1:

```python [1]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next: return head
        # 链表个数
        num = 0
        p = head
        while p:
            num += 1
            p = p.next
        k = num - k % num
        p = head
        # 找前一段链表
        while k > 1:
            p = p.next
            k -= 1
        head1 = p.next
        if not head1: return head
        #前一段链表最后至空
        p.next = None
        p = head1
        # 后一段链表和前一段链表连接起来
        while p.next:
            p = p.next
        p.next = head
        return head1
```

代码2:

```python [2]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or not k: return head
        num = 0
        dummy = ListNode(0)
        dummy.next = head
        p1 = dummy
        p2 = dummy
        # 计算个数
        while p1.next:
            num += 1
            p1 = p1.next
        #print(num)
        # 找前一段链表
        k = num - k % num
        #print(k)
        while k :
            p2 = p2.next
            k -= 1
        
        # 连接
        p1.next = dummy.next
        dummy.next = p2.next
        p2.next = None
        
        return dummy.next
```



```java [2]
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p1 = dummy;
        ListNode p2 = dummy;
        int num = 0;
        // 计算个数
        while (p1.next != null) {
            num++;
            p1 = p1.next;
        }
        // 找到前一段链表
        k = num - k % num;
        while (k != 0) {
            p2 = p2.next;
            k--;
        }
        // 连接
        p1.next = dummy.next;
        dummy.next = p2.next;
        p2.next = null;

        return dummy.next;
    }
}
```

