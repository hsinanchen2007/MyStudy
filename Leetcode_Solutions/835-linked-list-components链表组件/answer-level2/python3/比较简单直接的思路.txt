### 解题思路
![image.png](https://pic.leetcode-cn.com/ad2c6765eec42f3284948fc2eff57a4210f782406da178c9377fbb2dbe36b4e5-image.png)

有点意外竟然一次通过而且执行用时击败了这么多。。。。可能是没啥人用python3做这个题吧。
思路贼简单，就是给出的链表依次看这个元素在G里面有没有，有的话就记last是有，True，没有就是False。
如果发现一个数存在而上一个数不存在，即更新前的last是false，就说明增加了一个，给res+1即可

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
        G = set(G)
        last = False
        while head:
            if head.val not in G:
                last = False
            elif last == False:
                res += 1
                last = True
            head = head.next
        return res
```