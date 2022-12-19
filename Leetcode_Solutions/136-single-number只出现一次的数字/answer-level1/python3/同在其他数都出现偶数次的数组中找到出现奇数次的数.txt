异或运算
- 交换律：a ^ b = b ^ a
- 任何数与0异或为其本身 0 ^ n = n
- 相同的数异或为0: n ^ n = 0

因此偶数次出现的数异或为0，奇数次出现的异或为本身，因此遍历异或结果为唯一出现奇数次的数
```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums)):
            res ^= nums[i]
        return res
```

当然若有两个出现奇数次的数，结果为这两个数异或a^b，
找到结果不为1的位置，再次异或遍历获取其中一个数a
(a^b) ^ a = b即获取另一个数

数再多，规律更复杂，老实用字典统计数据，根据条件返回结果即可。

更多位运算题目见：位运算题集
https://blog.csdn.net/the_harder_to_love/article/details/104451915