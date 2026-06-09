### 解题思路
简单直观的思路
1. 编写一个函数weight，用题目方法确定某个数的权重
2. 将(weight(x), x)作为key，用来排序，输出第k个即可

### 代码

```python3
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:        
        def weight(x):
            cnt = 0
            while x != 1:
                if x % 2 == 0:
                    x = x // 2
                else:
                    x = 3 * x + 1
                cnt += 1
            return cnt

        nums = [i for i in range(lo, hi+1)]
        nums.sort(key=lambda x:(weight(x), x))
        return nums[k-1]
```