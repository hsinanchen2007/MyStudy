# 思路：
相比39题，这一题要求数字可以重复，那么我们可以使用一个字典统计每个数出现的次数（key：数字，value：出现次数）；又要求重复的组合只能出现一次，那么我们可以对字典的key在组合里的出现次数做限制。为了不浪费时间在遍历不可能等于`target`的组合上，我们对字典的key进行排序，当key的值大于`target`时，就不对后面更大的数字做判断了。

# 算法步骤
1. 使用`Counter`统计每个数出现的次数，得到一个字典`count_nums`，其中key是数字，value是出现次数
2. 对字典的key排序，使用`nums`保存
3. 递归函数中是一个for循环，查找元素大于等于当前数字的组合情况。即每次循环表示查找：一定包含该数，且其他数大于或等于该数的组合。循环内部有三种情况：
    1. 当前数字`nums[j]`大于`target`，那么后面比`target`更大的数字就不用遍历了，直接返回；
    2. 当前数字`nums[j]`等于`target`，找到了可行组合，后面比`target`更大的数字也不用遍历了，并且这个数字在当前组合中只会出现一次；
    3. 当前数字`nums[j]`小于`target`，那么要判断该数的出现次数从少到多的情况，最少出现1次，最多出现`count_nums[nums[j]]`次。又有三种情况：
        1. 如果该数取了m个后大于了`target`，那么出现更多次数的情况不用考虑了，组合中出现该数的所有情况判断完毕，跳出循环；
        2. 如果该数取了m个刚好等于`target`，找到了可行组合，组合中出现该数的所有情况判断完毕，跳出循环；
        3. 如果该数取了m个还是小于`target`，那么我们再一次递归，从下一个大于该数的元素开始找和等于`target-nums[j] * m`的组合（你可能会问，为啥不继续考虑取m+1个`nums[j]`的情况？别急，我们这里的思路是在每次循环中把`nums[j]`出现m次的情况考虑完，防止漏解，下一次循环自然会考虑`nums[j]`出现m+1次的情况~）

我们用来保存可行解的数组`ans`指针作为函数参数传递，这样每次在找到可行解之后可以直接添加，最终返回`ans`即可。

# 代码：
```python []
def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
    from collections import Counter
    if len(candidates) == 0:
        return []
    count_nums = Counter(candidates)
    nums = sorted(list(count_nums.keys()))
    n = len(nums)
    ans = []
    
    def findSum(count_nums, nums, target, n, i, ans, combination):
        for j in range(i, n):
            if nums[j] > target:
                return
            if nums[j] == target:
                ans.append(combination+[nums[j]])
                return
            for m in range(1, count_nums[nums[j]]+1):
                if nums[j] * m > target:
                    break
                elif nums[j] * m == target:
                    ans.append(combination+[nums[j]] * m)
                    break
                else:
                    findSum(count_nums, nums, target-nums[j] * m, n, j+1, ans, combination+[nums[j]] * m)
                    
    findSum(count_nums, nums, target, n, 0, ans, [])
    return ans
```
