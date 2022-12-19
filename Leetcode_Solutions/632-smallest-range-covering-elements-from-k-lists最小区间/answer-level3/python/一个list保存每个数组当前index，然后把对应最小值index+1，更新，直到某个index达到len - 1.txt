```
class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        import sys
        import bisect
        k = [0] * len(nums)
        i_l = [len(i) for i in nums]

        l = 0
        r = 0
        q_m = sys.maxsize
        result = []
        q = [nums[i][0] for i in range(len(nums))]             
        sort_q = sorted(q)
        l = sort_q[0]
        r = sort_q[-1]
        
        while 1:
            if r - l < q_m:
                result = [l, r]
                q_m = r - l

            l_index = q.index(l)

            if k[l_index] == i_l[l_index] - 1:
                return result
            else:
                k[l_index] += 1

            q[l_index] = nums[l_index][k[l_index]]
            sort_q.pop(0)
            bisect.insort(sort_q, q[l_index])
            l = sort_q[0]
            r = sort_q[-1]
```
一个list保存每个数组当前index，然后把对应最小值index+1，更新，知道某个index达到len - 1
执行用时 :988 ms, 在所有 python 提交中击败了11.11%的用户
效率有点低，大家看看还能整么优化下？
