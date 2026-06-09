### 解题思路
1、当前这个数是1就+1，不是的话，计数的count清零，重来，每次count和max_value进行对比就可，取最大值
2、结束

### 代码

```

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ##换一个思路，只要当前的值是1，就加1，不然就直接清零
        count = 0
        max_value = 0
        for i in range(len(nums)):
            if nums[i]==1:
                count+=1
                if count>max_value:
                    max_value = count
            else:
                count = 0
        return max_value


```