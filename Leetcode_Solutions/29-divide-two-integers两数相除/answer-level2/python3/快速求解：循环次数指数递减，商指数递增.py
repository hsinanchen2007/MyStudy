- 特别在溢出判断也不要使用乘法，谢谢某位朋友的提醒，我已经更正我的马虎
- 另外对于取负算不算乘法，可以看成-x=0-x
- 用时在 46ms 左右
- 简单的去思考这个题，
- 很容易想到所求就是求一个除数的整数倍的数，
- 使其最接近被除数。
- 于是得需要一种方法来加速，
- 使得这个数趋近被除数的速度非常快，
- 很显然，指数级增长（递减）无疑是最快的
- 所以这里就采用了这样的思想
# - **算法分析：构造问题的子问题：**
- 要求一个非常接近被除数同时是除数的整数倍的整数，那么可以将这个数从1开始不停的倍增，直到其超过了除数
- 这时，应该取最近一次的未超过除数的最大数作为新的"被除数"，并进行同样的步骤得到这个“被除数”所最逼近的数
- 不停的将一个问题产生的不精确解生成一个子问题，来求解
- 当无法找到一个整数满足时，即是递归停止的边界
- 下面给出一个例子：
![image.png](https://pic.leetcode-cn.com/3eff5d45c98b8e4b8a2518eb6201f83eb17826a6ea3b47512b1c4ed11c13fc13-image.png)
```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (dividend>0 and divisor>0)or(dividend<0 and divisor<0):
            tag = 1
        else:
            tag = -1
        res = self.divCreas(abs(dividend), abs(divisor))
        if tag == -1: res=0-res
        if res > (2<<30)-1:return (2<<30)-1
        elif res < 0-(2<<30):return 0-(2<<30)
        return res
    def divCreas(self, dividend: int, divisor: int) -> int:
        ex,count = divisor,0
        t,m = 0,1
        if dividend < divisor:
            return 0
        while dividend-t-ex>=0:
            t += ex
            count+=m
            m+=m
            ex+=ex
        if dividend-t>0:
            return count+self.divCreas(dividend-t,divisor)
        return count        
if __name__ == "__main__":
    s = Solution()
    res = s.divide(10,-3)
    print(res)
```
