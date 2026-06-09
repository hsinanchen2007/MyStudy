### 解题思路
先排序
双指针，L，R 加上一个固定指针k。
k最小，范围0 - n-3（或者到nums[k] > 0终止）
L范围k+1 - R-1，我们这边while条件语句设的R>L
R范围L+1 - n-1
我本来想搞个set（tuple（i）） 把结果中重复的给去掉的，结果倒数第二个超多0那个超时了。那就没办法了，前面再加个while吧，while nums[k-1] == nums[k] 的时候就k+=1好了（相等的时候输出结果是相同的）。考虑到边界效应，k加过头了大于n-1就不好了，那我加了个k <=n-3,多运算一次问题不大。

反正我思路抄第二的那个人的，别人的代码我看着眼睛疼就没去看他，自己写了一份。我一开始搞的暴力解O（n3），怎么优化都超时。。。

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        nums.sort()
        k = 0 
        res = []
        while nums[k] <= 0 and k <= n-3:
            if k > 0:
               while nums[k] == nums[k-1] and k <= n-3:
                  k+=1
            R = n-1
            L = k +1 
            while R > L:
                if nums[k] + nums[R] + nums[L] == 0:
                    res.append([nums[k],nums[L],nums[R]])
                    R -= 1 
                    L += 1 
                if nums[k] + nums[R] + nums[L] > 0:
                    R -= 1 
                if nums[k] + nums[R] + nums[L] < 0:
                    L += 1
            k+=1 
        resf = [list(i) for i in set(tuple(i) for i in res)]
        return resf 
```