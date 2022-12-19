```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # 预先排序
        nums = sorted(nums) 
        ans = []
        def backtrack(path, part_nums):
            # 每次递归进来的时候都需要加入到集合中，可以把想象为一个树的遍历，从树的顶点到任意一个点都有路径
            ans.append(path)
            for i in range(len(part_nums)):
                # 避免相同的元素重复，因此对于相同的元素只回溯一次
                if i == 0 or part_nums[i]!=part_nums[i-1]: 
                    # 为了避免顺序不同产生重复，因此加入顺序使得非递减排列
                    if len(path) == 0 or path[-1] <= part_nums[i]:
                        backtrack(path+[part_nums[i]], part_nums[:i]+part_nums[i+1:])
        backtrack([], nums)
        return ans
```
