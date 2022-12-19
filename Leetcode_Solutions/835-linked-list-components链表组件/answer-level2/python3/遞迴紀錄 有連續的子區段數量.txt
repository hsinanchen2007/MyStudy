### 解题思路
遞迴紀錄 有連續的子區段數量
有發生連續就一直累加 current
當發生斷點 就將current歸零 並且對結果 res +1 表示 紀錄有發生的子集

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:       
        res = 0
        current = 0
        def Next(head): 
            nonlocal res, current
            # nonlocal current
            if head.val in G:
                current += 1
                if current == 1 :
                    res += 1    
            else :
                current = 0

            if not head.next:
                return            
            Next(head.next)

        Next(head) 
        return res 
```