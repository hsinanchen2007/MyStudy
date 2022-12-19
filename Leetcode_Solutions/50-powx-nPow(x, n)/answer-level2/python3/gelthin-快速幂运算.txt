### 解题思路
有点像两个数相除的那个问题. [29.两数相除](https://leetcode-cn.com/problems/divide-two-integers/)

快速幂运算 参见百度[快速幂](https://baike.baidu.com/item/%E5%BF%AB%E9%80%9F%E5%B9%82/5500243?fr=aladdin)

阿里 2020/3/23 日 机试题, 计算 n*2^(n-1)
第一题好像是n个人，任意去一些人组成一队，再从队中取一个队长，问有多找种可能。
是快速幕……C（n,1）*1 + C(n,2)*2 ... + C(n,n)*n = n*2^(n-1)

第二题是给一个棋盘，里面有一个终点一个起点和障碍若干，棋子可以上下左右移动，还可以翻转（中心对称），问从起点到终点的最短距离.翻转次数最多为5

[python3 输入模板](https://bestsort.cn/2019/04/21/70/)

看了官方题解，循环和递归都不错。递归需要构造一个辅助函数。

$x^n = [x^{n//2}]^2*x$  or  $x^n = [x^{n//2}]^2*1$ # 判断 n 是否整除 2

循环的解法，则是考虑二进制，设 $n = \sum_{i=0}^k {b_i}\cdot2^i$：
$x^n = x^{\sum_{i=0}^k b_i \cdot 2^i} = \Pi_{i=0}^k x^{b_i\cdot2^i}$
$= \Pi_{i=0}^k \quad (x^{2^i} \text{ if } b_i==1 \text{ else } 1)$

当前值为 x, x^2, x^4, x^8, x^16, 每次判断对应的 b_i 是否为 1, 然后选择是否乘以当前值， 然后让当前值翻倍。




### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        ## 快速幂运算 阿里 2020/3/23 日 机试题, 计算 n*2^(n-1)
        r = 1
        if n == 0:
            return 1
        flag = False
        if n <0:
            flag = True
            n = -n
        while n>0:
            if n%2==1:
                r = r*x
            x = x*x
            n = n//2
        if flag:
            return 1/r
        else:
            return r
```