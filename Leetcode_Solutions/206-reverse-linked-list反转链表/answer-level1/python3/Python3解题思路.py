这里需要注意3个重要的点：
1. 迭代和递归一个是正向思路，一个是逆向思路。迭代是从前往后一步步反转，而递归是从后往前一步步反转
2. 递归思路需要注意什么时候去指定新的表头，即当递归到最后一个元素时来指定它为新的表头
3. 这个时候定义了递归方法，应该以class的对象属性作为新的head，而不能以递归方法中的属性作为新的head

```
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        self.new_head = None
        def __reverse(pre, cur):
            if cur.next is not None:
                __reverse(cur, cur.next)
            else:
                self.new_head = cur
            cur.next = pre
        if head is None:
            return head
        __reverse(None, head)
        return self.new_head
```
