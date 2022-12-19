
和363题代码框架一样，区别是找需要记录下最大子序和的起点和终点  
主函数整体结构都一样的

依次做这几道题，方便理解  
[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
[84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)
[85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)
[363. 矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)
[面试题 17.24. 最大子矩阵](https://leetcode-cn.com/problems/max-submatrix-lcci/)  
   
  


```python3 []
    #leetcode 363 代码套路一样
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:
        row = len(matrix)
        col = len(matrix[0])
        maxArea = float('-inf')                     #最大面积
        res = [0, 0, 0, 0]

        for left in range(col):                     #从左到右，从上到下，滚动遍历
            colSum = [0] * row                      #以left为左边界，每行的总和
            for right in range(left, col):          #这一列每一位为右边界
                for i in range(row):                #遍历列中每一位，计算前缀和
                    colSum[i] += matrix[i][right]

                startX, endX, maxAreaCur= self.getMax(colSum)#在left，right为边界下的矩阵中，前缀和colSum的最大值
                if maxAreaCur > maxArea:
                    res = [startX, left, endX, right]        #left是起点y轴坐标，right是终点y轴坐标
                    maxArea = maxAreaCur
        return res
    
    #这一列中，找最大值，同时记录起点，终点
    #因为传进来的是列的前缀和，所以返回的起点、终点代表的是行坐标
    def getMax(self, nums):
        n = len(nums)
        maxVal, curSum = nums[0], nums[0]       #初始化最大值
        startIndex, end, start = 0, 0, 0        #初始化临时起点，起点，终点
        for i in range(1,n):
            if curSum<0:                        #前缀和小于0了，前面就不要了，从当前开始
                curSum = nums[i]
                startIndex = i                  #前面的前缀和小于0了，需要重置起点，从当前开始才有可能成为最大值
            else:
                curSum = curSum + nums[i]
            
            if curSum > maxVal:
                maxVal = curSum
                start = startIndex             #记录下前面的起点，默认0，或者是curSum<0后，重新更新的起点
                end = i                        #终点是当前坐标
        return start, end, maxVal              #起点，终点，最大前缀和（最大面积）

```
```python3 []
    # 这里是 leetcode 363 的题解，用于参考
    # 1、先计算每列的前缀和
    # 2、计算每行的最大子数组和
    # 固定左右边界，前缀和+二分
    # 划分左右边界，并求出在此边界下，每行的总和
    # 通过二分法找不超过K的矩阵
    # 当然以行划分也行，为什么要以列为边界，因为题目中说了 如果行数远大于列数
    # https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/solution/gu-ding-zuo-you-bian-jie-qian-zhui-he-er-fen-by-po/
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        row = len(matrix)
        col = len(matrix[0])
        res = float("-inf")
        for left in range(col):                     #从左到右，从上到下，滚动遍历
            colSum = [0] * row                      #以left为左边界，每行的总和
            for right in range(left, col):          #这一列每一位为右边界
                for i in range(row):                #遍历列中每一位，计算前缀和
                    colSum[i] += matrix[i][right]
                
                res = max(res, self.dpmax2(colSum, k))# 在left，right为边界下的矩阵，求不超过K的最大数值和
                if res==k:return k
        return res

    # Kadane’s algorithm
    # O(n)
    # 最大子片段的和
    # 遍历该数组， 遍历之前设置了两个变量 max_ending_here, max_so_far
    # 其中 max_ending_here 用于记录遍历过程中， 如果把当前元素 x 强制规定为子数列的最后一个元素时， 能找到的最大子数列的总和是多少
    # 由于真正的最大子数列必然存在一个结尾元素， 所以只需要从每个位置计算出的 max_ending_here 中， 找到最大值， 就是全局的最大子数列的值。
    # max_so_far 用于记录遍历过程中， 所发现的最大的 max_ending_here
    # 一次遍历之后， 变量 max_so_far 中存储的即为最大子片段的和值。
    # https://blog.csdn.net/lengxiao1993/article/details/52303492
    def dpmax2(self, colSum, k):
        max_ending_here = max_so_far = colSum[0]
        for i in range(1, len(colSum)):
            max_ending_here = max(colSum[i], max_ending_here + colSum[i])
            max_so_far = max(max_so_far, max_ending_here)
        return min(max_so_far, k)

    # 二分法
    # O(nlog(n))
    # 最大子片段的和
    # https://zhuanlan.zhihu.com/p/68827223
    # https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
    # def dpmax(self, colSum, k):
    #     import bisect
    #     arr = [0]
    #     cur = 0
    #     res = float('-inf')
    #     for tmp in colSum:
    #         cur += tmp
    #         # 二分法
    #         loc = bisect.bisect_left(arr, cur - k)  #找到比cur-k大的最小值 
    #         # print(cur ,k,loc)
    #         if loc < len(arr):                      #插到后面说明，不存在比cur-k大的值
    #             res = max(cur - arr[loc], res)      #比cur-k大的最小值就是arr[loc]，总和-这个值就是好最大片段和
    #         bisect.insort(arr, cur)                 #把累加和加入arr
    #     # print('->',colSum,arr,res)
    #     return res
    #     # // 对于当前的前缀和，找数中大于等于cur-k的最小元素
    #     # // 设找到的数为p，则cur-k<=p，必有 cur-p<= k
    #     # // 所有最小的p，使得cur-p的值最大，且该值小于等于k

    # 计算colsum中<=k的最大值
    # O(n^2)
    # 超长测试用例，超时
    # def dpmax3(self, colSum, k):
    #     re = float('-inf')
    #     for i in range(len(colSum)):
    #         sum = 0 
    #         for j in range(i, len(colSum)):
    #             sum += colSum[j]
    #             if sum>re and sum<=k: 
    #                 re = sum
    #             if max==k:return k 
    #     return re
```
