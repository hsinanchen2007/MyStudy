## 思路
+ 先去掉字符串的最后空格
+ 将字符串按照空格分组
+ 取分组后的最后一项
+ 计算它的长度
+ 完事儿

## 代码
```Python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.rstrip().split(" ")[-1])
```