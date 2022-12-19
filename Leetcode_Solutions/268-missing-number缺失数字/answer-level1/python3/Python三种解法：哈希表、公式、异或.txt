一、使用哈希表：
思路：使用一个长度为len(nums)的列表arr并初始化为0，然后将nums中出现的数的索引位置设置为1，最后遍历arr看哪一个索引位置出现0即为所求。
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        arr = [0]*(len(nums)+1)
        for i in nums:
            arr[i] = 1
        for i in arr:
            if i == 0:
                return arr.index(i)
```
二、使用公式
思路：如果nums中不缺少任何值那么整个nums的和应该为n(n+1)/2，然后用这个值减去nums中的元素剩下的即为所求
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = n*(n+1)//2
        for i in nums:
            res = res - i
        return res
```
三、应用位运算：异或
思路：应用异或运算的性质a^b^a=b,即异或具有去重的性质。用nums中的值去异或nums的索引，若nums不缺失任何值，那么必然能够找到与索引相等的值，所以用nums中的值去异或nums的索引最后剩下的即为所求。
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = len(nums)
        for i in range(ans):
            ans = ans ^ i ^ nums[i]
        return ans
```

