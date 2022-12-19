
**思路：
递归的每次输入为(一组单词words,比较的位置i),words中每一个word的倒数第i位后的字母组成相同。
通过倒数第i位将输入的单词进行分组，如果某个单词单独一组，那么它一定不是其他单词的后缀。
在递归的过程中累加不含后缀的单词的长度求出结果。**

用示例做讲解：
"time" "me" "bell"

["time","me","bell"]比较倒数第1位
{'e':["time","me"],'l':["bell"]}
bell 单独一组，一定不会是其他单词的后缀。 ans += len("bell")+len("#")

["time","me"] 比较倒数第2位
{'m':["time","me"]}

["time","me"] 比较倒数第3位
{'i':["time"]}
time 单独一组，一定不会是其他单词的后缀。 ans += len("time")+len("#")

对应的递归实现如下：
```python []
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        def helper(words,i):
            dic = {}
            for w in words:
                if i<=len(w):
                    if w[-i] not in dic:
                        dic[w[-i]] = []
                    dic[w[-i]].append(w)
            for v in dic.values():
                if len(v)>1:
                    helper(v,i+1)
                else:
                    self.ans += len(v[0]) + 1
        
        self.ans = 0
        helper(set(words),1)
        return self.ans
```