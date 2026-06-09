这个题目不需要递归也可以完成。考虑清楚情况就行了，如果`shorter==longer`，结果就是`k*shorter`，如果不是，输出的数组就是从`shorter*k`到`longer*k`，数组元素之间的间隔就是`longer-shorter`。可能这个发现不到。

```python
class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k==0:
            return []
        elif shorter==longer:
            return [k*shorter]
        return [i for i in range(shorter*k,longer*k+1,(longer-shorter))]
        
```
