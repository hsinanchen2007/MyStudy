### 解题思路
使用哈希表储存遍历过的节点，当存在环形链时即返回该节点。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        dic=dict()
        prev=head
        n=0
        while prev:
            if prev in dic:
                return prev
            else:
                dic[prev]=n
            n+=1
            prev=prev.next
        return None
```

![image.png](https://pic.leetcode-cn.com/f25a578bdd27f1b4bf983a3b4934ea1af0241a44494b9780306658a378bddbc4-image.png)
