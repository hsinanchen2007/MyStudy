###
1.暴力求解：计算出所有子序列和取最大的，时间复杂度o(n^2),空间复杂度o(1)
只是讲下思路，这种方法提交会超时

### 
```python3
class Solution:
    def maxSubArray(self, nums):
        max_subarray = nums[0]
        for i in range(len(nums)):
            tmp=nums[i]
            max_subarray=max(max_subarray,tmp)
            for j in range(len(nums)):
                if j>i: 
                    tmp+=nums[j]
                    max_subarray=max(max_subarray,tmp)
        return max_subarray
```
### 解题思路
2.贪心算法：这个官方题解说的比较明白，我只贴个我的代码

### 代码

```python3
class Solution:
    def maxSubArray(self, nums):
        sum=ans=nums[0]
        for n in nums[1:]:
            sum=sum+n if sum >0 else n
            ans = ans if ans>sum else sum
        return ans 
```
### 解题思路
3.动态规划：其实就是用一个数组dp做记录，dp[i]记录以nums[i]为结尾的最大子序列和。
实现方式就是dp[i]=max(dp[i-1]+nums[i],nums[i]),即以nums[i]为结尾的最大子序列要么是以它自己单独作为子序列，要么是它加上前面以nums[i-1]为结尾的最大子序列和dp[i-1],通过比较大小确定具体是哪个，本质上和贪心算法是一样的。
时间复杂度:o(n),空间复杂度:o(n)

### 代码

```python3
class Solution:
    def maxSubArray(self, nums):
        dp=[nums[0]]
        for n in nums[1:]:
            dp.append(max(dp[-1]+n,n))
        return max(dp) 
```
### 解题思路
3.1.动态算法调整：仔细思考发现其实根本不需要dp数组，每次都只需要获得前一个元素为结尾的最大子序和，所以调整一下，时间复杂度还为o(n),空间复杂度变为o(1)。这个时候可以看到动态规划方法和贪心算法基本一样，dp=max(dp+n,n)和前面贪心算法的sum=sum+n if sum >0 else 其实是一回事

### 代码

```python3
class Solution:
    def maxSubArray(self, nums):
       ans=dp=nums[0]
        for n in nums[1:]:
            dp=max(dp+n,n)
            ans=ans if ans>dp else dp
        return ans
```
### 解题思路
4.分治算法：解题思路都写在注释

### 代码

```python3
class Solution:
    def maxSubArray(self, nums):
        """
        分治算法
        中心元素索引号记为c=(0+len(nums))//2,
        最大子序列要么在中心元素左边nums[:c]，要么在中心元素右边nums[c+1:]，要么包含中心元素
        如果是包含中心元素的情况：最大子序列和=max(左子序列nums[:c]中以nums[c-1]为结尾的最大子序列和,0)+nums[c]+max(右子序列nums[c+1:]中以nums[c+1]为开始的最大子序列和,0)
        递归的方式求解整个问题
        """
        if len(nums)==1: return nums[0]
        #别人的题解都是把中心元素并入到左子序列或右子序列中，我为了理解方便没有这样做，这样导致len(nums)===2时，nums[c+1:]为[]
        #为了解决这个问题把len(nums)==2也作为终止条件
        if len(nums)==2: return max(nums[0],nums[1],nums[0]+nums[1])
        c=(0+len(nums))//2   
        maxLeft = self.maxSubArray(nums[:c])
        maxRight = self.maxSubArray(nums[c+1:])
        #接下来就是求解以包含中心元素的最大子序列和，我用的动态规划方法，也可以用暴力方法
        #从这里也可以看到，这个题分治方法只能作为一种思路，实现起来要比动态规划方法复杂
        maxLeftTail=nums[0]
        maxRightHead=nums[-1]
        #动态规划方法求得以nums[c-1]为结尾的最大子序列和
        for n in nums[1:c]:
            maxLeftTail=max(maxLeftTail+n,n)
        #动态规划方法求得以nums[c+1]为开头的最大子序列和
        for n in reversed(nums[c+1:-1]):
            maxRightHead=max(maxRightHead+n,n)
        #包含中心元素的最大子序列不一包括以nums[c-1]为结尾的子序列，也不一定包括以nums[c+1]为开头的子序列
        #通过实例[-1,0,2]很好理解这一点
        maxCenter=max(0,maxLeftTail)+nums[c]+max(0,maxRightHead)
        return max(maxLeft,maxCenter,maxRight) 
```