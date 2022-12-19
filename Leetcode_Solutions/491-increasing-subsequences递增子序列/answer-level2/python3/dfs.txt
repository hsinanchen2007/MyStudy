用一个dict记录当前前缀下、当前位置某个字符是否已经被使用
```
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(start, tmp):
            dic = {}
            if len(tmp) > 1:
                res.append(tmp)
            for i in range(start, len(nums)):
                if dic.get(nums[i], 0):
                    continue

                if len(tmp) == 0 or nums[i] >= tmp[-1]:
                    dic[nums[i]] = 1
                    dfs(i + 1, tmp + [nums[i]])


        dfs(0, [])
        return res
```
