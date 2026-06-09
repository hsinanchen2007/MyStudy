### 解题思路
此处撰写解题思路
![FireShot Capture 022 - 面试题06. 从尾到头打印链表 - 力扣（LeetCode） - leetcode-cn.com.png](https://pic.leetcode-cn.com/a9cc19ca8ea40a0a16a83d040a0fd9a4b4aae6855b20bbf1c9b3bd8a9476708a-FireShot%20Capture%20022%20-%20%E9%9D%A2%E8%AF%95%E9%A2%9806.%20%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89%20-%20leetcode-cn.com.png)

##### 额外空间O(n)  时间消耗为遍历一遍O(n)

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head is None:
            return []
        ans = self.reversePrint(head.next)
        ans.append(head.val)
        return ans
```
    