![2345截图20200329204018.png](https://pic.leetcode-cn.com/6674e73a3db0f5ac08dcb74e89240e4bdd24faf387fe0e433d29cd0d90eef575-2345%E6%88%AA%E5%9B%BE20200329204018.png)


class Solution:
    def findLucky(self, arr: List[int]) -> int:
        length = len(arr)
        nums = [0 for i in range(length + 1)]
        for num in arr:
            if num <= length and num >= 0:
                nums[num] += 1
        result = -1
        for i in range(length + 1):
            if i == nums[i] and nums[i] != 0:
                result = nums[i]
        return result