### 解题思路
同习题 [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

官方题解思路似乎比我的方法更加精炼。官方题解的评论中有人提到野指针，但似乎不对。

官方题解中是碰到相同的，就改一次 prev.next 

我是当碰到不相同的，才开始改 prev.next。 这又是延后处理，需要后面再补充一步。
[gelthin-二维 DP-延后处理](https://leetcode-cn.com/problems/different-ways-to-add-parentheses/solution/gelthin-er-wei-dp-by-gelthin/)

[gelthin-for循环延后处理经常漏掉](https://leetcode-cn.com/problems/count-and-say/solution/gelthin-forxun-huan-yan-hou-chu-li-jing-chang-lou-/)


下面也给出了按照官方代码改写的代码。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return None
            
        prev, p = head, head.next

        while p != None:
            if p.val == prev.val:
                pnext = p.next
                del p
                p = pnext
            else:
                prev.next = p
                prev = p
                p = p.next
        # 延后处理，需要这里再补充一步
        prev.next = None  # 若样例不删最后一个节点，可以不用此。但避免 1->1 删除了最后一个节点出错
        return head

```
### 按照官方代码改写的代码

``` python 3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        current = head
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next   # 这一个代码很好.没有延后处理， 即使 1-> 1-> 1 也对。
            else:
                current = current.next
        return head


```
