大家好，我的博客是[erik-chen的博客](https://erik-chen.github.io/)，欢迎交流！
### 解题思路
一个以 $a_1$ 为首项，以 $1$ 为公差，以 $n$ 为项数的等差数列的和为 $target$，
$$target=na_1+\frac{n(n-1)}{2}$$
转化为
$$a_1=\frac{target-\frac{n(n-1)}2}n$$

目标是找出所有满足条件的 $n$、$a_1$ 对，
思路是对 $n$ 从 $2$ 开始遍历（题目要求最少是 $2$ 个数），验证 $a_1$ 是否为正整数。
有一个问题是 $n$ 遍历到多少呢？
其实不需要特地去算 $n$ 的上限，随着 $n$ 的递增，$a_1$ 递减，当 $a_1 <= 0$ 时跳出循环即可。

Python 代码如下:

```python [-Python 3]
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        for n in range(2, target+1):
            temp = target - n*(n-1)//2
            if temp <= 0:
                break
            if not temp % n:
                a_1 = temp // n
                res.append([a_1 + i for i in range(n)])
        return res[::-1]
```
![image.png](https://pic.leetcode-cn.com/05575b1800469b33b19749953bbc15b949ef41eb58d0019eb9c9e8c6ee5a7443-image.png)

