### 解题思路
避免了多次排序的时间复杂程度

### 代码

```python
class Solution(object):
    def lastStoneWeight(self, stones):
        #桶排序
        buckets = [0] * 1001
        for c in stones:
            buckets[c] += 1
        i = 1000
        j = i - 1
        while i >= 0:
            buckets[i] = buckets[i] % 2 
            if buckets[i] == 0:
                i -= 1
                j = i - 1
            else:
                if buckets[j] != 0:
                    buckets[i-j] += 1
                    buckets[i] -= 1
                    buckets[j] -= 1
                else:
                    j -= 1
            if j < 0:break
        if i < 0:return 0
        else:return i
            
```