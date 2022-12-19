直接上代码:
```
def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        odd = [i for i in A if i%2 == 1]        # 选出所有奇数
        even = [i for i in A if i%2 == 0]       # 选出所有偶数
        return even+odd
```
