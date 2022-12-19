### 解题思路
双变量，一个记录最大连续1的个数，一个记录当前的连续1的个数

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxlen=0
        cur=0
        for i in nums:
            if i==1:
                cur+=1
            else:
                cur=0
            if cur>maxlen:
                maxlen=cur
        return maxlen
```

![image.png](https://pic.leetcode-cn.com/ffdd1b0902fa741bb58564ecbd2c9184a001da35c152c06b0f0b5d24701ac4e2-image.png)
