### 解题思路
整数为n，相加等于n的一组i个整数为base、base+1……base+i-1
满足关系式：base = [n-1-2-……-(i-1)]//i
基于此，可以遍历从1到n的整数，利用上述公式计算出每一组连续整数。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        div = target
        res = []
        for i in range(1, div):
            target = target - i
            if target <= 0:
                break
            if target % (i + 1) == 0:
                base = target // (i+1)
                res.append([ j for j in range(base, base+i+1)])           
        return sorted(res, key = lambda x : x[0])
```