### 解题思路
![image.png](https://pic.leetcode-cn.com/38925a29db756404ffda66989e42a0e92f99af2f9aa961c598e0a8fcb57e349d-image.png)

首先我们做一下分析，如果我们有一个前驱结点，想要把这个节点之后的两个节点交换位置，如何做呢？

```
1 -> 2 -> 3 -> 4

如果想要将前驱结点之后的两个节点2，3交换位置，
1 -> 3 -> 2 -> 4

实际上就是改变1，2，3 这三个节点的指针即可
1 -> 3
2 -> 4
3 -> 2

```

利用python的特性，可以使用一行代码实现：

```python
# pre                   => 1
# pre.next              => 2
# pre.next.next         => 3
# pre.next.next.next    => 4
pre.next,pre.next.next,pre.next.next.next = pre.next.next,pre.next,pre.next.next.next
```


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        
        pre = ListNode(0)
        pre.next = head
        ans = pre
        while pre.next and pre.next.next:
            pre.next,pre.next.next,pre.next.next.next = pre.next.next,pre.next,pre.next.next.next
            pre = pre.next.next
            
        return ans.next
```