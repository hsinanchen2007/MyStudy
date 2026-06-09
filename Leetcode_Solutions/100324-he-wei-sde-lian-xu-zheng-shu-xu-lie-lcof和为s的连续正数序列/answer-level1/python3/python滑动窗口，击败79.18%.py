### 解题思路
![屏幕快照 2020-03-21 11.29.56.png](https://pic.leetcode-cn.com/b874dbefeb7031fce436cefd0c696f294c6702a8664342d2ae5b227a26c521a8-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-21%2011.29.56.png)


### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i, j, sum, res = 1, 1, 0, []    # 左右指针，部分和，结果列表
        while i < target / 2:   # 因为i超过target/2后，sum一定比target大了
            sum += j    # 更新当前部分和
            while sum >= target:    
                if sum == target:
                    res.append([a for a in range(i, j+1)])
                sum -= i    # i不断右移
                i += 1
            j += 1
        return res
```