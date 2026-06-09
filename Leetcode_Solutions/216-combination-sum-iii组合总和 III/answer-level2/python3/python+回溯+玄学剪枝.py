# 首先是剪枝不完全的代码
# ![UC截图20191128173158.png](https://pic.leetcode-cn.com/dc542c834e3862c75fb4e2e9442ba1dbdad608fe9ec7fe88792e5429ebc00139-UC%E6%88%AA%E5%9B%BE20191128173158.png)
# class Solution:
#     def combinationSum3(self, k: int, n: int) -> List[List[int]]:
#         nums = [x for x in range(1,10)]
#         ans = []
#         def helper(i, tmp, target):
#             if target == n and len(tmp) == k:
#                 ans.append(tmp)
#                 return
#             if i > len(nums) - k + len(tmp):
#                 return
#             if i == len(nums) or n - target < nums[i]:
#                 return
#             helper(i+1,tmp+[nums[i]],target+nums[i])
#             helper(i+1,tmp,target)
#         helper(0, [], 0)
#         return ans

# 然后是玄学剪枝后的代码，主要思想就是每次剔除最后不可能构成k大小的数组的组合
# 通过计算递归次数发现性能比上一个要好很多，尤其是在n，k比较大的时候，下面是例子演示
# ```
没有剪枝的时候
def combinationSum3(k: int, n: int):
    nums = [x for x in range(1,10)]
    ans = []
    bijiao = []
    def helper(i, tmp, target,bijiao):
        if target == n and len(tmp) == k:
            ans.append(tmp)
            return
        # if i > len(nums) - k + len(tmp):
        #     return
        bijiao.append(1)
        if i == len(nums) or n - target < nums[i]:
            return
        helper(i+1,tmp+[nums[i]],target+nums[i],bijiao)
        helper(i+1,tmp,target,bijiao)
    helper(0, [], 0,bijiao)
    return ans,bijiao

n = 30
k = 6
ans,bijiao = combinationSum3(k,n)
print(ans)
print(sum(bijiao))
# ```
# ![UC截图20191128192830.png](https://pic.leetcode-cn.com/511ddfc042fcd08b4b03e4712b86df2ee7ac797c7f813bc666e58dd92d262cda-UC%E6%88%AA%E5%9B%BE20191128192830.png)
# 剪枝过后（把上面注释部分取消注释）
# ```
def combinationSum3(k: int, n: int):
    nums = [x for x in range(1,10)]
    ans = []
    bijiao = []
    def helper(i, tmp, target,bijiao):
        if target == n and len(tmp) == k:
            ans.append(tmp)
            return
        if i > len(nums) - k + len(tmp):
            return
        bijiao.append(1)
        if i == len(nums) or n - target < nums[i]:
            return
        helper(i+1,tmp+[nums[i]],target+nums[i],bijiao)
        helper(i+1,tmp,target,bijiao)
    helper(0, [], 0,bijiao)
    return ans,bijiao

n = 30
k = 6
ans,bijiao = combinationSum3(k,n)
# print(combinationSum3(k,n))
print(ans)
print(sum(bijiao))
# ```
# ![UC截图20191128193029.png](https://pic.leetcode-cn.com/2f3a11ad586e08f842d93d998c66ddcdadadebe49830762d3bfa5669176eba3a-UC%E6%88%AA%E5%9B%BE20191128193029.png)
# 发现递归次数明显减少
# 但是不知道为啥，在leetcode上的运行时间反而更长了😂


