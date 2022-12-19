解题思路：分别构建奇数，偶数的列表，相加。还有一种方法就是利用快排的算法，这样不用额外耗费内存，但是写起来比较麻烦。
代码：
```
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        even = [i for i in A if i % 2 == 0]
        odd = [i for i in A if i % 2 != 0]
        return even + odd
```
