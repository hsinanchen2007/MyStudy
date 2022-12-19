### 解题思路
countList.append(asecCount+1): 加1是因为每次比较的是两个数，有asecCount次递增，其实是比较了asecCount+1个数

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        lenNums = len(nums)

        if lenNums <= 1:  # 原数组长度为0或1
            return lenNums

        if len(set(nums)) == 1:  # 原数组长度大于1但元素全都相同
            return 1

        asecCount = 0  # 统计递增次数
        countList = []
        for i in range(lenNums - 1):
            if nums[i] < nums[i + 1]:  # 连续递增
                asecCount += 1
                countList.append(asecCount + 1) # 每递增一次，就将asecCount+1填入countList
            else:
                # countList.append(asecCount+1) # 也可以放在这里
                asecCount = 0  # 一旦遇见递减，则将asecCount置零，重新开始计数
                countList.append(asecCount + 1)
                continue
    
        return max(countList)
```