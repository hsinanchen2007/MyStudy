```
#
# @lc app=leetcode.cn id=1186 lang=python
#
# [1186] 删除一次得到子数组最大和
#

# @lc code=start
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        len_a = len(arr)
        left = [0] * (len(arr) + 1)
        right = [0] * (len(arr) + 2)
        rst = -999999
        for i in range(len_a):  #  先计算从左到右  以及从右到最大的最大的值，然后在单独算 去除一个数字的最大的值
            left[i+1] = max(left[i] + arr[i], arr[i])
            right[len_a-i] = max(right[len_a-i+1] + arr[len_a-i-1], arr[len_a-i-1])
            rst = max(left[i+1], right[len_a-i], rst)
           
        for i in range(len_a):
            if i ==0:
                rst = max(right[1], rst)
                continue 
            if i == len_a:
                rst = max(left[len_a-1], rst)
                continue
            rst = max(left[i-1]+right[i+1], rst)
        return rst 




# @lc code=end

if __name__ == '__main__':
    a = Solution()
    a = a.maximumSum([1,-2,0,3])
    print(a)
```
