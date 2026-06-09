### 解题思路
这里代码似乎不用判负处理下面也是对的，但有判负，比没有判要好一些。

和前一道习题一样 [263. 丑数 gelthin-去除因子](https://leetcode-cn.com/problems/ugly-number/)。
实际上做除法，不用判负。

[这里似乎无法用到平方翻幂法](https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/)

进阶做法，不用循环或者递归
官方题解中 用 3^19 % n == 0 是一个不错的 idea。


### 代码

```python3
class Solution:
    def isPowerOfThree(self, n: int) -> bool:  
        # 这里似乎无法用到平方翻幂法 https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
        if n<=0:  
            return False
        while n%3 == 0:
            n = n/3
        return n==1
    
```