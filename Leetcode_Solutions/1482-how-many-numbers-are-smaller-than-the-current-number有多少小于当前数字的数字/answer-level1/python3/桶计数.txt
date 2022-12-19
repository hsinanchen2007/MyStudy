### 解题思路
1. 定义一排桶 backet = [0] * 101 , 其中 backet[n] 里存放数字 n 出现的次数
2. backet[:n]的和即为小于n的数字的总和

### 代码

```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        backet = [0] * 101

        for item in nums:
            backet[item] += 1
        
        return [sum(backet[:n]) for n in nums]
```