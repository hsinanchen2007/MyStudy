![Screenshot from 2019-08-18 11-38-46.png](https://pic.leetcode-cn.com/ca161b0f0007a77bf2b1c0f98b25061e1ee483490b87efc335c7b3ac6092fefc-Screenshot%20from%202019-08-18%2011-38-46.png)

    class Solution:
        def search(self, reader, target):
            """
            :type reader: ArrayReader
            :type target: int
            :rtype: int
            """
            # 按照数组最大的可能性设置左右边界
            left = 0
            right = 20000
            while left < right:
                mid = (left + right + 1) >> 1 # 右中位数
                if reader.get(mid) == 2147483647: # 如果越界，则右边界收缩
                    right = mid - 1
                elif reader.get(mid) > target: # 如果大于目标值，则右边界收缩
                    right = mid - 1
                else:
                    left = mid
            return left if reader.get(left) == target else -1 # 返回结果