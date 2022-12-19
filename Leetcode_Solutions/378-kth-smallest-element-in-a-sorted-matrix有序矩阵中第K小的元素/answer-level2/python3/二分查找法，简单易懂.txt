解法：二分查找法，根据题目可得左上角元素最小，右下角元素最大，计算中间值。然后计算小于等于目标值的元素个数，根据递增规则，从右上角开始查找，类似于题目“二维数组的查找”

时间复杂度：O(nlogk) ，k=最大值-最小值
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        # 计算小于等于目标值的元素个数，根据递增规则，从右上角开始查找
        def count_num(m, target):
            i = 0
            j = len(m) - 1
            ans = 0
            while i < len(m) and j >= 0:
                if m[i][j] <= target:
                    ans += j + 1
                    i += 1
                else:
                    j -= 1
            return ans
        
        #  思路：左上角元素最小，右下角元素最大，计算小于等于中间值的元素个数
        left = matrix[0][0]
        right = matrix[-1][-1]
        # 二分法查找
        while left < right:
            mid = (left + right) >> 1
            # print(' mid = ', mid)
            count = count_num(matrix, mid)
            # print('count = ', count)
            if count < k:
                left = mid + 1
            else:
                right = mid
        return left
```
