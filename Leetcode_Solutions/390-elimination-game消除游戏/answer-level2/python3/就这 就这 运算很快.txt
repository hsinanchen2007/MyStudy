执行用时 :56 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了7.14%的用户
```
class Solution:
    def lastRemaining(self, n: int) -> int:
        if n==1:
            return 1
        result = 2 #第二行的开头
        l = n//2 # 第二行的个数
        i=1
        while l>1:
            # 偶数行到奇数行，奇数行的开头
            if l%2 == 0:
                result = result
                i +=1
            if l%2 == 1:
                result += 2**i
                i += 1
            l = l//2
            if l>1:
                # 奇数行到偶数行，偶数行的开头
                result += 2**i
                l = l//2
                i +=1 
        return result
```
