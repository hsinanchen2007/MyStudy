一、算法思想
1.用临时变量temp记录数组A中所有偶数的和。在判断数组A中元素是否为偶数时使用位运算&而不使用数学运算取余从而提升运算速度。
2.创建数组res=[]用于保存结果。
3.逐一遍历查询数组queries中元素，用val、index表示其中各元素，并按如下步骤执行：
（1）当A[index]为偶数时，用temp减去该元素。
（2）将A[index]自加val进行更新。
（3）当更新后的A[index]为偶数时，将该元素加入temp。
（4）将temp添加到保存结果的数组res。
4.返回数组res。
二、算法实现
```
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        temp = 0
        for num in A:
            if num & 1 == 0:
                temp += num
        res = []
        for val, index in queries:
            if A[index] & 1 == 0:
                temp -= A[index]
            A[index] += val
            if A[index] & 1 == 0:
                temp += A[index]
            res.append(temp)
        return res
```
三、复杂度分析
1.时间复杂度：O(N+Q)。其中N为整数数组A的长度，Q为查询数组queries的长度。
2.空间复杂度：O(Q)。保存结果的数组占用空间为O(Q)。