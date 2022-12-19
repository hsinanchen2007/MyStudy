### 解题思路
官方题解感觉挺清晰的啊。
位运算还可以用在找 [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/), 这里 x & (-x) 还可以用于[260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)

从官方题解中可以学到很多。

x & (-x) 只保留 x 二进制的最右边的第一个 1, 其余全部会为0。 因为 -x 补码表示法是 x 先取反再最右边加 1；袁春风老师的计算机系统课讲取负数也相当于：保留 x 的最右边第一个 1 及更右边的 0 不动，把第一个1左边的数全部取反，这样理解更方便。

x & (x-1) 则相当于 x 最右边第一个1及其更右边的0全部变为0

如果 x 二进制只有一个1，则 x&(x-1) == 0 成立，并 x&(-x)==x 成立。

补码取模运算，模 2^32，由于 32 位 signed int 的表示范围 -2^31 ~ 2^31-1, 于是 -2^31 - 1 = -2^31-1+2^32 = 2^31-1


不过这里还是有一个疑问，对于 32 位 signed int, 最小的负数 - 2^31 = 1000 0000 0000 0000 0000 0000 0000 0000， 也只有一个 1，这里的位运算方法是否会失效？ 

所以保守起见，最好先判断一下是不是负数，预处理。

就像 对 x *-1 一样，会有溢出风险。知乎上 [Int 类型的最小负数乘以-1等于多少？](https://www.zhihu.com/question/28319117)
还是其自身。

令 mask = a^b, mask & (-mask) 只保留 mask 二进制的最右边的第一个 1 被用于[260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/) 用来区分开两个都只出现一个的数


自己的解法是 O(log n)的，每次一直除以 2， 到无法整除为止，除以2前先判断是否能整除。


### 代码





```python3

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        
        mask = n&(n-1)
        return mask == 0

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        
        mask = n&(-n)
        return mask == n

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n<=0: 
            return False
        if 1==n: # 论代码习惯的重要性，错写成 1=n 会直接报错
            return True
            
        while n>1:
            if n%2 == 0:
                n = n/2
            else:
                return False
        return True

```