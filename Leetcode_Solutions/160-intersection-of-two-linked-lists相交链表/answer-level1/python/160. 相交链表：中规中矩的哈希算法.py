![image.png](https://pic.leetcode-cn.com/10ad62f9ebd6e122bd76958bc97ffd0a55786294429f4cd8a3e3d9b0056fd9cc-image.png)

没有脑筋急转弯

```python []
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        d = set()
        while headA:
            d.add(headA)
            headA = headA.next
        while headB:
            if headB in d:
                return headB
            headB = headB.next
```
