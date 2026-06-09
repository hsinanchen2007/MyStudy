### 解题思路
直接用for i in range(n): for j in range(sqrt(i))的方式通不过, 因为是O(n^2), 中间有很多重复的操作
直接对每个素数乘以range(2,n), 标记那些一定不是素数的数, 避免去除以每个数range(2,n)

其中还有两个改进的小trick

https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/
这个大佬的值得一看
### 代码

```python3
class Solution:
    def countPrimes(self, n: int) -> int:
        from math import sqrt
        mask, res = [1]*n, 0
        for i in range(2, int(sqrt(n))+1): # 遍历到sqrt(n)就可以. 
            if mask[i]:
                for j in range(i*i, n, i): # 本应从2*i开始, 不过为了避免重复(2x4, 4x2), 从i*i开始
                    mask[j] = 0
        for i in range(2, n):
            if mask[i]: res+=1
        return res

```

大佬代码学习下, 只有100ms
```
def countPrimes(self, n: int) -> int:
        if n <= 2: return 0
        
        nums = [1]*n
        nums[0] = nums[1] = 0
        for i in range(2, int(n ** 0.5) + 1): # 所以别用sqrt了
            if nums[i]:
                nums[i*i : n: i] = [0] * (( n-1 - i*i)//i + 1) # 前半部分的切片学习下; 后半部分(( n-1 - i*i)//i + 1)是计算切片的长度, 因为切片不是连续的是有间隔i的
        return sum(nums)
```