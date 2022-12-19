## 思路:

这个道题就像排队,先找个排头`dummy`,然后依次从`head`节点放入`dummy`,只需要依次`dummy`现有节点比较,插入其中!

```python []
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
     	# 找个排头
        dummy = ListNode(-1)
        pre = dummy
        # 依次拿head节点
        cur = head
        while cur:
        	# 把下一次节点保持下来
            tmp = cur.next
            # 找到插入的位置
            while pre.next and pre.next.val < cur.val:
                pre = pre.next
            # 进行插入操作
            cur.next = pre.next
            pre.next = cur
            pre= dummy
            cur = tmp
        return dummy.next
```



```java []
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            while (pre.next != null && pre.next.val < cur.val) pre = pre.next;
            cur.next = pre.next;
            pre.next = cur;
            pre = dummy;
            cur = tmp;
        }
        return dummy.next;
    }
}
```



一看执行时间`2000ms`,排名靠后,不应该哎!看了别人代码,原来是因为我们每次都要从头比较,但是测试集很多都是顺序排列的,没必要从头开始,我们直接比较最后一个`tail`,放在后面!

```python []
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        # 找个排头
        dummy = ListNode(float("-inf"))
        pre = dummy
        tail = dummy
        # 依次拿head节点
        cur = head
        while cur:
            if tail.val < cur.val:
                tail.next = cur
                tail = cur
                cur = cur.next
            else:
                # 把下一次节点保持下来
                tmp = cur.next
                tail.next = tmp
                # 找到插入的位置
                while pre.next and pre.next.val < cur.val:
                    pre = pre.next
                # 进行插入操作
                cur.next = pre.next
                pre.next = cur
                pre= dummy
                cur = tmp
        return dummy.next
```



```java []
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        ListNode pre = dummy;
        ListNode tail = dummy;
        ListNode cur = head;
        while (cur != null) {
            if (tail.val < cur.val) {
                tail.next = cur;
                tail = cur;
                cur = cur.next;
            } else {
                ListNode tmp = cur.next;
                tail.next = tmp;
                while (pre.next != null && pre.next.val < cur.val) pre = pre.next;
                cur.next = pre.next;
                pre.next = cur;
                pre = dummy;
                cur = tmp;
            }
        }
        return dummy.next;
    }
}
```

