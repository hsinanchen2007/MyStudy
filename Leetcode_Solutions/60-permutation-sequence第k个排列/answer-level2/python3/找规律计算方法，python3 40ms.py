执行用时:40ms,在所有 Python3 提交中击败了97.44%的用户
思想就是剩余序号（re，初始为k-1）通过除以一个递减的阶乘，来得到当前位应当是剩余元素中的第几个。
从剩余元素集合中添加对应元素到答案，然后从剩余元素集合中删除该元素，重复上述操作，直到某次余数为0。
最后顺序添加剩余元素集合中的元素即可。
```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        Nset = [i for i in range(1, n+1)]
        re = k - 1
        tmp = n
        ans = ""
        while re != 0:
            tmp_factorial = self.__factorial(tmp - 1)
            quotient = re // tmp_factorial
            re = re % tmp_factorial
            ans += str(Nset[quotient])
            del Nset[quotient]
            tmp -= 1
        
        for N in Nset:
            ans += str(N)
        
        return ans
            
        
    def __factorial(self, n: int) -> int:
        res = 1
        for i in range(1, n+1):
            res *= i
        
        return res
```
