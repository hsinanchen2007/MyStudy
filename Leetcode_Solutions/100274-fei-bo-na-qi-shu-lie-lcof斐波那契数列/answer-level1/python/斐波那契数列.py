# 三种方法：
## 1. 递归
直接使用递归公式。缺点是：重复计算，费时费力，容易造成栈溢出。

时间复杂度：O(2^N)
空间复杂度：O(1)


## 2. 记忆化数组
用数组存储1～N时计算出来的值，求解N+1时，直接相加。缺点是：使用了长度为N附加列表。

时间复杂度：O(N)
空间复杂度：O(N)


## 3. 动规
f(n+1) = f(n) + f(n-1)
以此类推，使用a，b两个变量存储f(n)前两个数列计算出的值。

时间复杂度：O(N)
空间复杂度：O(1)

## 3'. 数学解法：
![IMG_0211.jpeg](https://pic.leetcode-cn.com/32a0ae8fad694b6fddda21fb6f31aa29b6690d7b83d7b0895055d5a71df71f10-IMG_0211.jpeg)

![IMG_0212.jpeg](https://pic.leetcode-cn.com/7f47e7f2e3dfcf22169d302287267ac7cb8d6e2d0765d34c05dc538cfe7894ac-IMG_0212.jpeg)

时间复杂度：O(logN)



Tips:
1. Python可以直接交换两个元素的位置，不需要借助第三个变量！！！
2. Python的int的大小取决于电脑本身的内存，可以理解为无穷大
2. 因此仅需对最后的结果取模即可，而其他编程语言中，需要对每次计算的和取模。因为在加法过程中，就可能溢出
3. 1e9+7的含义：
![Screenshot 2020-04-06 at 11.29.30.png](https://pic.leetcode-cn.com/f9d12da55e57f352af44477c1d69b78b15f9f804fed8414db112da36aa5536ce-Screenshot%202020-04-06%20at%2011.29.30.png)

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        a = 0
        b = 1
        
        for _ in range(n):
            a,b = b,a+b

        return a % 1000000007
        # return int(a % int(1e9+7))
```