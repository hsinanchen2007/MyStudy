蓄水池抽样，第n个输入的数据，以1/n的概率采样，就可以保证前面的都是1/n了，具体证明可以采取数学归纳法。
详情，如下[链接](https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/)可以查看 


```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        res = None
        cur = self.head
        c = 0
        while cur:
            if not random.randint(0,c):
                res = cur.val
            c+=1
            cur = cur.next
        return res


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
```