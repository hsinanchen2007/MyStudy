### 解题思路
1.将lic拆分出来并转换成小写字母
2.排序（将words按照字符串长度排序）
2.利用collections.Counter()函数的集合操作

### 代码

```python3
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        str_lice=''
        res=''
        for char in licensePlate:
            if char.isalpha():
                str_lice+=char
        str_lice=str_lice.lower()
        str_col=collections.Counter(str_lice)
        words.sort(key=len)
        for string in words:
            if collections.Counter(string)&str_col==str_col :
                return string



```