首先写出dp方程：dp[i] = dp[比i小（最接近i）的2的整数次方的数] + dp[i - 前面的那个数],如果i直接是2的次方数，那么dp[i]=1
ok,有了dp方程，直接上代码
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        import math
        dp = [0] * (num+1)
        for i in range(1,num+1):
            a = pow(2,int(math.log(i,2)))
            b = i - a
            if b == 0:
                dp[i] = 1
            else:
                dp[i] = dp[a] + dp[b]
        return dp
```
提交看一下结果：
![UC截图20191216195855.png](https://pic.leetcode-cn.com/115942f7fc71839d753fa867d42e7747b07ee385557eda7ac92b7f4e1736ac05-UC%E6%88%AA%E5%9B%BE20191216195855.png)

What，这么慢( ఠൠఠ )，想一想优化方案
估计是在算a的时候太慢了，达到了O(log n)的时间复杂度，有没有什么办法能降低这个复杂度呢。
其实大部分dp问题之所以慢，都是应为做了一些无意义的计算，而减少这种计算通用的办法就是记忆化，那么这里我们也可以使用记忆化。
我们可以用一个变量bite来储存当前比i小的2的整数次方的数，直接用i - bite就等于b，而且a就等于bite，因此完全不用再去算a，
只不过每次我们都需要对i进行判断i%bite == 0，来对bite进行更新。

下面是修改后的代码：
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        bite = 1
        dp = [0] * (num+1)
        for i in range(1,num+1):
            if i % bite == 0:
                bite = i
            b = i - bite
            if b == 0:
                dp[i] = 1
            else:
                dp[i] = dp[bite] + dp[b]
        return dp
```
提交看一下结果：
![UC截图20191216202539.png](https://pic.leetcode-cn.com/e04c41e8d8564093dbde723ffe7ecbf2be14068ed53c401353c805d34796a954-UC%E6%88%AA%E5%9B%BE20191216202539.png)


咋一看好像还可以，但是我们还可以对上面的代码再简化一下，去掉一些冗余的代码
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        bite = 1
        dp = [0] * (num + 1)
        for i in range(1, num + 1):
            if i % bite == 0:
                bite = i
                dp[i] = 1
            else:
                dp[i] = dp[bite] + dp[i - bite]
        return dp
```
在提交一下，终于差不多了
![UC截图20191216200757.png](https://pic.leetcode-cn.com/292fdba23854b66db93646cc8167c57886061771707dc30df2650e4394c57d14-UC%E6%88%AA%E5%9B%BE20191216200757.png)

欢迎大家一起交流，一起刷题，带带我这个菜鸡(☆▽☆)





