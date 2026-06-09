### 解题思路
正则表达式
就很python的解法

### 代码

```python3
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        license_ = licensePlate.lower()                 #大写 -> 小写
        license = re.findall(r'[a-z]', license_)        #选取牌照中的字母
        dic = collections.Counter(license)              #统计牌照中的字母个数
        words.sort(key=len)                             #words按单词长度排序
        for word in words:
            if collections.Counter(word) & dic == dic:
                return word
        return -1
```