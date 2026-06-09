### 解题思路
我们需要判断的是
1：每个单词的字母是否都在字符串中
2：每个单词中同一字母出现的次数是否小于等于字符串中同一字母出现的次数

### 代码
错误思路：大家观看我第一次写的代码，判断错在没有对比字母出现的次数
```python3
class Solution:
    def countCharacters(self, words, chars: str) -> int:
        str1 =""
                len1 = 0
                for i in range(len(words)):
                    if len(words[i]) > len(chars):
                        continue
                    for j in words[i]:
                        if j in chars:
                            len1 += 1
                        if len1 == len(words[i]):
                            str1 += words[i]

                    len1 = 0

                return len(str1)



```python3正确思路
class Solution:
    def countCharacters(self, words, chars: str) -> int:
        chars1 = collections.Counter(chars)#把字符串按字母出现次数编成字典key：字母，value：出现次数
        ans = ""
        for i in words:
            c = collections.Counter(i)#把列表中单词按字母出现次数编成字典key：字母，value：出现次数
            if all(c[j] <= chars1[j] for j in c):#判断条件:如果所有单词中的字母出现次数均<=字符串中字母出现的次数，说明字符串可以拼出该单词
                ans += i

        return len(ans)

```