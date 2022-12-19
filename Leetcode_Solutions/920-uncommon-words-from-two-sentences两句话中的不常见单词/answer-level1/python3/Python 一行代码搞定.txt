## 思路
+ 将两个字符串合成一个
+ 分割成单词
+ 取出现次数为1个的单词
+ 利用生成器生成列表

## 代码
```Python
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        return [i for i in (A + ' ' + B).split() if (A + ' ' + B).split().count(i) == 1 ]
```