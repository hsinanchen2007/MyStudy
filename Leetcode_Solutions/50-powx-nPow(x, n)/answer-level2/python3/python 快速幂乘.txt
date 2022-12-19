为了避免超时，思想就是每次乘的数是上次的平方，如果当前剩余的次方数小于当前乘数的次方数，则将乘数的次方数重新从1开始翻倍。
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            temp_n = -n
        else:
            temp_n = n
        
        tmp_mul = 1
        tmp_res = x
        residue = temp_n
        res = 1
        
        while residue >= 1:
            if tmp_mul > residue:
                tmp_mul = 1
                tmp_res = x
            else:
                res = res * tmp_res
                residue -= tmp_mul
                tmp_res = tmp_res * tmp_res   
                tmp_mul *= 2
        
        if n < 0:
            return 1/res
        else:
            return res
```
执行用时 :
44 ms, 在所有 Python3 提交中击败了89.60%的用户
内存消耗 :
13.8 MB, 在所有 Python3 提交中击败了5.24%的用户