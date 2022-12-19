![Capture.JPG](https://pic.leetcode-cn.com/9c0e8099d75186cd2df640b5499e82a3baf1ee3ab3940afcc38d80b4ae9fd9ab-Capture.JPG)
以上图为例
输入[1,17,5,10,13,15,10,5,16,8]
我们取第一个点，然后依次取其最近的凹凸点
得到[1, 17, 5, 15, 5, 16, 8],即答案
思路比较简单，代码写得比较拖沓，大家知道思路过后自己写更好

思路如下：
(1)取第一个点
(2)然后去取最近的一个凹点或凸点
(3)然后重复以上步骤
ps:注意最后一个点的处理以及相等时的处理
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        #贪心思想，建议画以一个X,Y轴，每次找最近的解
        maxLen = 0
        if(len(nums)<=1):
            return len(nums)
        if(len(nums)==2):
            if(nums[0]!=nums[1]):
                return 2
            else:
                return 1
        res = [nums[0]]
        pre = nums[0]
        for i in range(1,len(nums)-1):
            if(nums[i]>pre and nums[i]>nums[i+1]):
                pre = nums[i]
                res.append(nums[i])
            elif(nums[i]<pre and nums[i]<nums[i+1]):
                pre = nums[i]
                res.append(nums[i])
            else:
                continue
        #对最后一个数进行处理
        if(len(res)>1):
            if(res[-1] > res[-2] and res[-1]>nums[-1]):
                res.append(nums[-1])
            elif(res[-1] < res[-2] and res[-1]<nums[-1]):
                res.append(nums[-1])
        else:
            if(res[0]==nums[-1]):
                return 1
            else:
                res.append(nums[-1])
        return len(res)
```
