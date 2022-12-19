```
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        nums = [int(''.join(row), base=2) for row in matrix]
        ans, N = 0, len(nums)
        for i in range(N):
            #记录包括第i行及以下的最大矩形面积
            j, num = i, nums[i]
            #j从i开始往下遍历
            while j < N:
                #num 从上到下与自己做位运算 只有上下两行同时为1 结果才为1
                num = num & nums[j]
                #如果num变成0 说明这矩形在这两行断了 跳出循环
                if not num:
                    break
                #l记录一行内的最大矩形 也就是连续的1的个数
                l, curnum = 0, num
                while curnum:
                    l += 1
                    #curnum是num和num左移（右移也一样）做位运算，只有相邻的两个数都是1，结果才为1
                    curnum = curnum & (curnum >> 1)
                #l为矩形的宽度
                #j-i+1为矩形的长度
                #如果ans=max(ans, l * (j - i + 1)) 就得到最大矩形面积
                ans = max(ans, min(l,(j-i+1))*min(l,(j-i+1)))
                j += 1
        return ans
```
