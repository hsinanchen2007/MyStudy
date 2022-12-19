### 解题思路
对于任意一个要爬的楼层数量n（从一楼到n+1楼），可以将他拆分成若干个爬两层楼和若干个爬一层楼
也就是将n拆分为=2k+m的形式
那么k的取值范围是[0, floor(n / 2)] ∩ N*

接下来就好办了，对于每一个可以取值的k
用插板法,在2里头插入1或者在1里头插入2，本质是一样的
相当于把k个球放进m+1个盒子里，可以有盒子为空

那么先借球，转换为k+m+1个球放进不能为空的m+1个盒子里，最后同时所有盒子减去1个球，排列数不变
k+m+1个球有k+m个不为空的缝可以插板，插入m个板的插入方式总共有C(k + m, m)种

对于每一种k而言都可用这种方式算，跑完循环即可
导入了Math的factoria(计算组合数) floor(可以不要，用int(n/2)+1也一样)
也可以用scipy计算组合数

### 代码

```python3
from math import factorial,floor

class Solution:
    def comb_1(self, n, m):
        return factorial(n) // (factorial(n - m) * factorial(m))

    def climbStairs(self, n: int) -> int:
        fn = floor(n / 2) + 1

        ans = 0

        for k in range(fn):
            m = n - 2 * k
            ans += self.comb_1(k + m, m)
        return ans

```