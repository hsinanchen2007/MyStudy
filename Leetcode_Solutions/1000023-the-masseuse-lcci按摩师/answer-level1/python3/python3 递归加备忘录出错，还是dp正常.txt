### 解题思路
此处撰写解题思路
python 递归超时了，很明显的dp问题，这个和那个斐波那契数列有点像
自定向下dp, 选择了nums[i] 说明必定不可以选择 nums[i-1]
不选择nums[i] 说明nums[i-1] 选择与否都可以。
a_i  表示不选择 nums[i]
b_i  表示选择 nums[i] 

如何更新 a_i 和 b_i ？ 
a_i = max(a_(i-1),b_(i-1))
b_i = a_(i-1) + nums[i]

如何初始化？
a_0,b_0 = 0,nums[0]

返回 选择最大的那个即可，就是选择 当前的nums[i] 和不选择的最大的那个


递归尝试加备忘录，但是结果出错了，key找错了，不太确定，下面也给了自己的递归+备忘录的方式
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        # n = len(nums)
        # # 迭代法：注意，你永远不会连续跳过3个预约。为什么不会？因为你总是可以接受中间的预约。
        # # 迭代法：如果你选择i，那么将永远不会选择i + 1，但是总会选择i + 2或i + 3。
        # def helper(i,flag,ans):
        #     if i>=n:
        #         return ans
        #     if flag:
        #         ans+=nums[i]
        #         return max(helper(i+2,True,ans),helper(i+2,False,ans))
        #     else:
        #         return max(helper(i+1,True,ans),helper(i+1,False,ans))
        # return max(helper(0,True,0),helper(0,False,0))
        n = len(nums)
        if n==0:
            return 0
        
        a,b = 0,nums[0]
        for i in range(1,n):
            ta = max(a,b)
            tb = a+nums[i]
            a,b = ta,tb
        return max(a,b)

```

```
# 以下是错误的备忘录的方式，暂时不知道如何解决？
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        memo = {}
        def helper(i,flag,ans):
            if i>=n:
                return ans
            if (i,flag) in memo:
                return memo[(i,flag)]
            if flag:
                ans+=nums[i]
                memo[(i,flag)] = max(helper(i+2,True,ans),helper(i+2,False,ans))
                return memo[(i,flag)]
            else:
                memo[(i,flag)] = max(helper(i+1,True,ans),helper(i+1,False,ans))
                return memo[(i,flag)]
        return max(helper(0,True,0),helper(0,False,0))
```
