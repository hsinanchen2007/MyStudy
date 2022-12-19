### 解题思路
#  这是简略版的，如果有！@#￥%……&*（）符号的存在，可以先历经替换成空格。
#  若空 返回 空
#  若只有符号 返回 空
# 其他正常运算

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0:
            return 0
        elif len(s.split()) == 0:
            return 0
        else:
            return len(s.split()[-1] )

```