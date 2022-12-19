### 解题思路
这里异或的方法很容易想到，似乎剑指offer 提到过此题。
但要知道 python 中 ^ 可以这么用倒不是很容易，可见博客 [Python中的XOR异或符号^运用](https://blog.csdn.net/weixin_44731100/article/details/89156141)

交换律：a ^ b ^ c <=> a ^ c ^ b
任何数于0异或为任何数 0 ^ n => n
相同的数异或为0: n ^ n => 0
a = [2,3,2,4,4]
2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3

这里官方第二种题解： 2*sum(set(nums)) -sum(nums) 虽然能快速解决，虽然不清楚 set() 函数的实现，但必然不是 O(n), 猜测至少是 O(nlogn)




### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = nums[0]  # 虽然这里也可以去 res = 0, 然后从下面开始 0^a = a
        for x in nums[1:]:
            res ^= x
        return res
```