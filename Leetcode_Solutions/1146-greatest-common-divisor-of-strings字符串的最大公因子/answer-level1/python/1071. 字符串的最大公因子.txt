### 解题思路
执行用时 : 20 ms , 在所有 Python 提交中击败了 71.79% 的用户 
内存消耗 : 12.8 MB , 在所有 Python 提交中击败了 6.90% 的用
第一步：先找到公共字符串gcd
第二步：当同时满足下面条件时即为字符串最大公因子：
    1.str1和str2的长度为gcd长度的整数倍
    2.gcd乘以该倍数得到str1和str2
第三步：如果不满足，则将gcd最末一个字符删掉，重复第二步

### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        gcd = ""
        for i in zip(*[str1, str2]):
            if len(set(i))>1:
                break
            gcd += i[0]
        len1=len(str1)
        len2=len(str2) 
        while gcd:
            if len1%len(gcd)==0 and len2%len(gcd)==0 and gcd*(len1//len(gcd))==str1 and gcd*(len2//len(gcd))==str2:
                break
            else:
                gcd = gcd[0:-1]
        return gcd  
```