### 解题思路
先找到数组里的上界，然后再用两重循环去更新中间的状态
number数组存储每个num的因子数
cur数组存储每个num的因子和

刚开始都赋0，第二重循环只需要成倍遍历即可，成倍遍历可以保证每次number增加1，cur也是加上当前的i值
最后按照要求从表里取出答案即可

### 代码

```python3
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        if len(nums) == 1:
            upper = nums[0]
        else:
            upper = max(*nums)
        number = [0 for i in range(upper+1)]
        cur = [0 for i in range(upper+1)]
        for i in range(1,upper+1):
            for j in range(i,upper+1,i):
                number[j] += 1
                cur[j] += i
        
        ans = 0
        for num in nums:
            if number[num] == 4:
                ans += cur[num]
        
        return ans
                
```