首先看看等差数列1,2,3,4,5
我们可以得到的等差子数列有
123,234,345
1234,2345
12345

根据规律可以总结出，长度为N的等差数列，等差子数列有
(N-2)*(N-1)/2

所以，通过一次循环，找到最长区间P-Q,用公式计算子数列个数。

class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        res = 0
        cur_num = 0
        for i in range(1,len(A)):
            if i == 1:
                old_diff = A[i] - A[i-1]
                cur_num = 1
            cur_diff = A[i] - A[i-1]
            if cur_diff == old_diff:
                cur_num += 1
            
            if cur_diff != old_diff:
                old_diff = cur_diff
                if cur_num >= 3:
                    res += (cur_num-2)*(cur_num-1)//2
                cur_num = 2
        
        if cur_num >= 3:
            res += (cur_num-2)*(cur_num-1)//2

        
        return res
