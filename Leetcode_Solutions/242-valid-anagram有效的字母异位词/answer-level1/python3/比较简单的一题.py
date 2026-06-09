### 解题思路
1、先统计两个字符串每种字符出现的次数 2、判断字符种类是否相等  3、每种字符出现次数是否相等

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        import collections

        num1 = collections.Counter(s)
        num2 = collections.Counter(t)
        if len(num1) != len(num2):
            return False
        for key in num1.keys():
            if num1.get(key) != num2.get(key):
                return False
        return True

```