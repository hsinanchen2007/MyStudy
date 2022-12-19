### 方法一：堆栈

* 每k个节点轮流进栈，轮流出栈。注意首尾相连的边界。
* 代码中，`start`和`tail`指向k个节点外的前一节点和后一节点。
* 时间复杂度: O(N); 空间复杂度: O(k)

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        start = dummy
        while True:
            # step1: push
            count = k 
            tail = start
            stack = []
            while(count and tail):
                tail = tail.next
                count -= 1
                stack.append(tail)
            if not tail:
                break
            # step2: pop
            tail = tail.next
            while(stack):
                curr = stack.pop()
                prev.next = curr
                prev = curr
            prev.next = tail
            start = prev
        return dummy.next
```


### 方法二：尾插

* 譬如，链表为 `1->2->3->4->5`，k为4。
* 最初我的想法是，从前向后依次翻转。
    * `1`指向`5`,`5<-1 2->3->4->5`，其中，前后两个`5`是同一个，想象一下有个环。
    * `2`指向`1`,`5<-1<-2 3->4->5`
    * `3`指向`2`,`5<-1<-2<-3 4->5`
    * `4`指向`3`,`5<-1<-2<-3<-4 5`，这样就结束了一组。
* 这种做法可以做，但是我写完发现需要存储五个指针，一是不简约，二是自己容易乱。毕竟，你在翻转之前，为了确定节点数是否够4个，`tail`指针会移动到`4`的位置，但是吧，你后面又没充分利用到`tail`。
* 相比之下，尾插的思想更加简洁。
    * `1`移到`4`后,`2->3->4->1->5`
    * `2`移到`4`后,`3->4->2->1->5`
    * `3`移到`4`后，`4->3->2->1->5`
* 这样一来，只需要存储指向`4`的指针`tail`和指向首元素的指针`prev`，每次把`prev`移到`tail`后面，其中借助`temp`指针的帮助。然后指定`next_prev`指针，初始时指向`5`，一次反转结束后，`prev`和`tail`都移到`next_prev`处，开始下一组。指针的分工非常清晰。
* 时间复杂度: O(N); 空间复杂度: O(k)

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 尾插法
        dummy = ListNode(0)
        dummy.next = head
        prev, tail = dummy, dummy
        while True:
            count = k 
            while(count and tail):
                tail = tail.next
                count -= 1
            if not tail:
                break
            next_prev = prev.next
            while(prev.next != tail):
                temp = tail.next
                tail.next = prev.next
                prev.next = prev.next.next
                tail.next.next = temp
            prev, tail = next_prev, next_prev
        return dummy.next
```

### 方法三：递归

* 基线：不足k个节点时，直接返回头结点。
* 递归：前k个尾插，k+1之后的节点送入反转函数，二者相连。
* 时间复杂度: O(N); 空间复杂度: O(n/k)

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 递归法
        count = k-1
        tail = head
        while(count and tail):
            count -= 1
            tail = tail.next
        # base case: return head
        if not tail:
            return head
        # iterative case: k+1后的节点送入递归, 前k个与k+1个后的链表相连，前k个做尾插
        last = self.reverseKGroup(tail.next, k)
        tail.next = last
        prev = head
        while(prev != tail):
            curr = prev.next
            prev.next = tail.next
            tail.next = prev
            prev = curr
        return tail
```