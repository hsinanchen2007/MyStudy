回忆一下组合数学是告诉我们如何写出一个全排列的:
1. P({1}) = { [1] }
2. P({1, 2}): 先复制P({1})中的每个排列 2次, 得到{[1], [1]}, 然后让2插入到所有可能位置, 即index=0,1. 获得{[2,1], [1,2]}
3. P({1,2,3}): 先复制P({1, 2})的每个排列 3次, 得到{[2,1],[2,1], [2,1], [1,2], [1,2], [1,2]}, 然后让3插入到所有可能位置, 即index=0,1,2. 获得{[3,2,1], [2,3,1], [2,1,3], [3,1,2], [1,3,2], [1,2,3]}
4. P({1,2,3, .., N}): 先复制P({1,2,..,N-1})的每个排列N次, 然后让N插入到所有可能位置, 即index=0,1,2,.., N-1. 这样就能得到最后所有排列结果.

```
# for  P(1, 2, 3), we should have P(1, 2) first, and copy it 3(current length) times to have six array. 
then put the additional 3 in three spots to have 6 different arrangement.
# to have P(1, 2), we should have P(1) first

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        if length <= 1:  # 递归退出条件
            return [nums.copy(),]
        A = self.permute(nums[:-1])
        B = []
        for arr in A:
            for i in range(length):
                new_arr = arr.copy()
                new_arr.insert(i, nums[-1])
                B.append(new_arr)
        return B
```
