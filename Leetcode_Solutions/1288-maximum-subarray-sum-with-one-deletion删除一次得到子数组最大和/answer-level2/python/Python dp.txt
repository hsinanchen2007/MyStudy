```
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # cur0表示未删时当前位置的最大值，cur1表示已删时当前位置的最大值
        cur0, cur1, ans, size = arr[0], 0, float("-inf"), len(arr)
        for i in range(1, size):
            cur1 = max(cur1+arr[i], cur0)      # 前面位置已删，删当前位置值
            cur0 = max(arr[i], cur0+arr[i])    # 上一个位置最大值为负值，上一个位置最大值为正值
            ans = max(ans, cur0, cur1)
        return ans if size > 1 else arr[0]
```
