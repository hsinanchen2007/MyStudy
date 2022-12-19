### 解题思路
同习题 [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shuang-zhi-zhen-jian-zhi-offerxi-ti-by-gelthin/)

这里由于是返回值，而不是删除节点，没有必要设置虚拟头结点。
#### 两次遍历
第一次遍历求出链表长度

##### 一次遍历
这里直接使用快慢指针一次遍历即可求解。



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        #prehead = ListNode(0)
        #prehead.next = head
        i, j = head, head  # 似乎没有必要 设 prehead 虚拟头结点
        for _ in range(k):
            j = j.next
        while j!= None:
            i = i.next
            j = j.next
        return i.val
```