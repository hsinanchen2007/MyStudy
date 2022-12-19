```python3
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        ans = head
        while head != None:
            if head.val == val:
                head = head.next
                ans = head
                continue
            if head.next != None and head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next
        return ans
```
看了下题解区有很多用了两次循环，其实遍历一次就可以了：
* 记录头结点到`ans`
* 遍历结点，如果当前结点的值需要被删除，则将头结点舍弃，也就是`head = head.next`，并更新`ans`
* 判断当前结点的`next`是否需要被删除，如果需要删除，删除方法是`head.next = head.next.next`；如果不需要删除，继续检查下一个结点
嗯，三句话讲清楚一件事，棒！btw，击败了`100%`的用户 (=,=)