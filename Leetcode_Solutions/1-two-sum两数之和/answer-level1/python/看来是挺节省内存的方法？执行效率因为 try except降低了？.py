执行用时 : 1168 ms, 在Two Sum的Python3提交中击败了39.26% 的用户
内存消耗 : 13.3 MB, 在Two Sum的Python3提交中击败了99.27% 的用户
```
#通过list.index()方法
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        for i in range(length):
            tmp = target - nums[i]
            try:
                if nums.index(tmp) != i: #如果找不到值会抛出异常
                    return [i, nums.index(tmp)]
                    break
            except: #抛出的异常利用 try except来承接
                continue

if __name__ == '__main__':
    nums = [2, 5, 5, 11]
    target = 10
    solution = Solution()
    result = solution.twoSum(nums, target)
    print(result)
```
