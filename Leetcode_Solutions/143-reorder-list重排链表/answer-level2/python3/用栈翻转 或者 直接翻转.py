## 思路:

思路一: 栈

想法: 把节点压入栈中, 再弹出来,不就可以实现倒过来了吗?

难点: 弹出多少? 弹出一半? 要考虑!

思路二:

用这方法, 先做一下下面两题

 [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/),这道题是翻转整个链表

 [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/),这道题是翻转链表的一部分

接下来, 用图说明方法:
![1563947840102.png](https://pic.leetcode-cn.com/96ce57a2e1dec7b065ab78c198fd308d603703c19eaf3ff14e0e7902a59f804f-1563947840102.png)

所以,有三步

1. 找中点
2. 翻转中点之后的链表(好多方法, `Python`和 `Java` 各用一种)
3. 依次拼接

## 代码:

思路一:

```python []
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head: return None
        p = head
        stack = []
        # 把所有节点压入栈中
        while p:
            stack.append(p)
            p = p.next
        # 长度
        n = len(stack)
        # 找到中点前一个位置 
        count = (n - 1) // 2
        p = head
        while count:
            # 弹出栈顶
            tmp = stack.pop()
            # 与链头拼接
            tmp.next = p.next
            p.next  = tmp
            # 移动一个位置
            p = tmp.next
            count -= 1
        stack.pop().next = None
```



```java []
class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        Deque<ListNode> stack = new LinkedList<>();
        ListNode p = head;
        while (p != null) {
            stack.push(p);
            p = p.next;
        }
        int n = stack.size();
        int count = (n - 1) / 2;
        p = head;
        while (count != 0) {
            ListNode tmp = stack.pop();
            tmp.next = p.next;
            p.next = tmp;
            p = tmp.next;
            --count;
        }
        stack.pop().next = null;
    }
}
```

思路二:

```python []
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head or not head.next: return head
        # 1 2 3 4 5
        fast = head
        pre_mid = head
        # 找到中点, 偶数个找到时上界那个
        while fast.next and fast.next.next:
            pre_mid = pre_mid.next
            fast = fast.next.next
        # 翻转中点之后的链表,采用是pre, cur双指针方法
        pre = None
        cur = pre_mid.next
        # 1 2 5 4 3
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        # 翻转链表和前面链表拼接
        pre_mid.next = pre
        # 1 5 2 4 3
        # 链表头
        p1 = head
        # 翻转头
        p2 = pre_mid.next
        #print(p1.val, p2.val)
        while p1 != pre_mid:
            # 建议大家这部分画图, 很容易理解
            pre_mid.next = p2.next
            p2.next = p1.next
            p1.next = p2
            p1 = p2.next
            p2 = pre_mid.next
```



```java []
class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        ListNode slow = head;
        ListNode fast = head;
        // 找中点 1 2 3 4 5 6
        while (fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        // 翻转中点, 才用插入法 1 2 3 6 5 4
        ListNode pre = slow;
        ListNode cur = slow.next;
        while (cur.next != null){
            ListNode tmp = cur.next;
            cur.next = tmp.next;
            tmp.next = pre.next;
            pre.next = tmp;
        }

        // 拼接 1 6 2 5 3 4
        ListNode p1 = head;
        ListNode p2 = slow.next;
        while (p1 != slow){
            // 建议大家这部分画图, 很容易理解的
            slow.next = p2.next;
            p2.next = p1.next;
            p1.next = p2;
            p1 = p2.next;
            p2 = slow.next;
        }
    }
}
```

