### 解题思路
如果还是要双指针才能提高效率啊！
![1582797608(1).png](https://pic.leetcode-cn.com/4a1a82a7898fa19c539f0f0ec6ece6f49541a4b66f2df7b12bdeef56ddee861c-1582797608\(1\).png)
1.nums.sort()

2.确定nums[i]，j从i+1开始递增(nums[j]递增），k从length-1开始递减(nums[k]递减)。
  nums[i]定死了，当nums[i]+nums[j]+nums[k]<0时，j ++,当nums[i]+nums[j]+nums[k]>0时,k--。
  这样把j和k逼死了，就只能有一种结果那就是nums[i]+nums[j]+nums[k] == 0,当然例外在于此时j>=k,那么nums[i]就没有配对
  的nums[j]和nums[k]使得它们加起来为0

3.对于确定的nums[i]得到了一个三元组以后，确定的nums[i]可能不止存在一解，那么在nums[i]+nums[j]+nums[k]已经等于0的   情况下，就只能nums[j],nums[k]同时变化，一个变大一个变小，直到j>=k。

4.至于去重，每找到一组nums[i]的配对nums[j]和nums[k]以后，去除重复的nums[j]和nums[k]。最后再对nums[i]去。这样就能   使最后的数组不存在重复的三元组。

### 代码

```python3
class Solution:
    def threeSum(self, nums):
        length = len(nums)
        if length < 3:
            return []
        res = []
        nums.sort()

        i = 0
        if nums[0] <= 0 and nums[length-1] >= 0:
            while i < length and nums[i] <= 0:
                num1 = nums[i]

                # 在nums[i+1,length]中寻找num2,num3
                j = i + 1
                k = length - 1
                while j < k:
                    while j < k and nums[i] + nums[j] + nums[k] < 0:
                        # num1固定，num2+num3偏小，能变大的只有num2
                        j += 1
                    while j < k and nums[i] + nums[j] + nums[k] > 0:
                        k -= 1
                    while j < k and nums[i] + nums[j] + nums[k] == 0:
                        res.append([nums[i], nums[j], nums[k]])
                        # 此时num1找到了num2和num3和为0，但是可能还存在他解，因此可num2变大，num3变小
                        # 去重
                        num2 = nums[j]
                        while j < k and num2 == nums[j]:
                            j += 1
                        num3 = nums[k]
                        while j < k and num3 == nums[k]:
                            k -= 1
                # num1去重
                while i < length and nums[i] <= 0 and num1 == nums[i]:
                    i += 1


        return res

```