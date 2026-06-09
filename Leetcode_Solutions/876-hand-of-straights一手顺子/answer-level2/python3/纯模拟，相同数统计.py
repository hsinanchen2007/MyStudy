用字典统计数字的出现次数，然后再按需减数或删除输出，这里利用了字典的默认遍历序等于定义序的性质，所以只排一次序O(nlogn)就行，剩下的遍历是O(n)时间。

```
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        hand.sort()
        d = collections.defaultdict(int)
        for i in hand: 
            d[i] += 1
        while d:
            for i in d:     #实际上只取了字典d的首元素
                for j in range(W):
                    if i + j not in d:
                        return False
                    d[i + j] -= 1
                    if d[i + j] == 0:
                        d.pop(i + j)
                break
        return True
```
