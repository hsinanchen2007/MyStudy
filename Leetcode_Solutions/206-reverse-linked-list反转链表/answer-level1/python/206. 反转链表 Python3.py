### 解题思路
思路如下：

```
def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        while curr:
            tmp = curr.next     # 暂存后面的信息
            curr.next = prev    # 将curr.val接到前面已经倒序的prev上
            prev = curr         # 更新prev
            curr = tmp          # 更新curr
        return prev
```
