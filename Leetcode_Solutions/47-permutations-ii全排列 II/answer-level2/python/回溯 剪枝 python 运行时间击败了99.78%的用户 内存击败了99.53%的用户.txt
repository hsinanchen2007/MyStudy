基于46题回溯算法的改进
发现加上nums.sort()以后居然运行时间变快了
![image.png](https://pic.leetcode-cn.com/5e082c724c8f10ecf735a41a13a48a0ee5701ae8bab163c29ca9eea2470bdd75-image.png)
可以借助[@ge-zi-xiao-mian-bao](/u/ge-zi-xiao-mian-bao/)画的图理解，十分清楚，再次感谢大佬！！
![image.png](https://pic.leetcode-cn.com/41f57bddde6a6361bda373150412c075b76723e8192ec14c272e5e20923c1831-image.png)
```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return nums
        if len(nums) == 1:
            return [nums]
        nums.sort()
        res = []

        def iterate(nums, tmp):
            if not nums:
                res.append(tmp)
                return
            visited = {}    # 改进
            for i in range(len(nums)):
                if nums[i] not in visited:  # 改进
                    iterate(nums[:i] + nums[i + 1:], tmp + [nums[i]])
                visited[nums[i]] = True
        iterate(nums, [])
        return res
```
