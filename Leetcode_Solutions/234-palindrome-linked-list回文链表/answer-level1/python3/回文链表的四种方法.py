### 方法一：堆栈

* 遍历链表，把每个节点都push到`stack`中。
* 再次遍历链表，同时节点依次出栈，二者进行比较。
* 时间复杂度：O(N); 空间复杂度：O(N)

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        stack = []
        # step1: push 
        curr = head
        while(curr):
            stack.append(curr)
            curr = curr.next
        # step2: pop and compare
        node1 = head
        while(stack):
            node2 = stack.pop()
            if node1.val != node2.val:
                return False
            node1 = node1.next
        return True
```

### 方法二：一半堆栈

* 利用快慢双指针`slow`和`fast`来遍历链表，以找到链表中间的位置。
* 链表的前一半入栈，后一半与出栈的节点依次比较。
* 需要考虑节点时奇数还是偶数，这取决于终止时`fast`为空还是`fast.next`为空。
* 时间复杂度: O(N); 空间复杂度: O(N)，但比方法一节省一半的空间。

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        stack = []
        slow = head
        fast = head
        # step1: push
        while(fast and fast.next):
            stack.append(slow)
            slow = slow.next
            fast = fast.next.next
        if fast: # 奇数
            slow = slow.next
        # step2: pop and compare
        while(stack):
            curr = stack.pop()
            if curr.val != slow.val:
                return False
            slow = slow.next
        return True
```

### 方法三：反转

* 算法
    * step1: 依然利用快慢指针`slow`和`fast`，慢指针在辅助指针`temp`和`prev`的帮助下边走边反转。当快指针走到底时，链表的前半边已经是反转后的了。
    * step2: 指针`node1`和`node2`从链表的中间分别向两边移动，并比较是否相等。
    * step3: (optional) 最终，借助step1的`slow`和`prev`指针，把链表恢复成原来的序列。
* 依旧要考虑奇偶，想清楚。
* 这里设立了`flag`标注结果，而不是直接return，因为一旦先return了，就不会跑后面的恢复链表算法了。
* 时间复杂度: O(N); 空间复杂度: O(1)。

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow = head
        fast = head
        prev = None
        flag = True
        # step1: reverse
        while(fast and fast.next):
            fast = fast.next.next
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        # step2: compare
        if fast: # 奇数
            node1 = prev
            node2 = slow.next
        else: # 偶数
            node1 = prev
            node2 = slow
        while(node1 and node2):
            if node1.val != node2.val:
                flag = False
            node1, node2 = node1.next, node2.next
        # step3: recover(optional)
        back = slow
        while(prev):
            temp = prev.next
            prev.next = back
            back = prev
            prev = temp
        return flag

``` 

### 方法四：递归

* copy官方题解。对于递归算法的底层实现，尤其是堆栈帧(stack frame)有详细的图解。
* 时间复杂度: O(N); 空间复杂度: O(N)。

```python []
def isPalindrome(self, head: ListNode) -> bool:

    self.front_pointer = head

    def recursively_check(current_node=head):
        if current_node is not None:
            if not recursively_check(current_node.next):
                return False
            if self.front_pointer.val != current_node.val:
                return False
            self.front_pointer = self.front_pointer.next
        return True

    return recursively_check()
```