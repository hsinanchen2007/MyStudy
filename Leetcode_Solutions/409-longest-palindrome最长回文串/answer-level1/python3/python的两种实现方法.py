### 解题思路

* 回文串的特点是正反序相等
* 同一字符串为偶数都符合，同一字符串为奇数，除了中间可以放一个外，其余的都必须减少一个变为偶数
* 遍历字符串，存在偶数则每次累加，存在奇数则每次累加且最终结果减一
----
* 优化方法思路1：利用整除和乘法运算获取偶数原值和奇数
* 优化方法思路2：利用结果为偶数，遍历值为奇数来判断奇数字符串
* 优化方法思路3: 利用结果的长度少于原字符串的长度来判断出现奇数字符串


### 代码

```python3
# class Solution:
#     def longestPalindrome(self, s: str) -> int:
#         res = 0
#         for key in set(s):
#             res += s.count(key) // 2 * 2
#             if res % 2 == 0 and s.count(key) % 2 == 1:
#                 res += 1
#         return res

class Solution:
    def longestPalindrome(self, s: str) -> int:
        res = 0
        for key in set(s):
            res += s.count(key) // 2 * 2
        return res+1 if res < len(s) else res
```