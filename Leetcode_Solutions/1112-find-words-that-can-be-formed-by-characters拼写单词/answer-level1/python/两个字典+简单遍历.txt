### 解题思路
1. 解题目标：
    - 用chars中的字母
    - 判断能否组合words中的每个单词，每次判断每个单词只能用一次
    - 找到能组合的所有单词
    - 返回所有单词的长度之和
2. 解题思路：
    - 构造chars的频率字典d
    - 构造chars的访问频次字典dd，频次默认为0
    - 遍历words
    - 取第一个word
    - 遍历word的每个字母i
    - i 是否在 d 中 , dd[i]是否小于等于d[i]
    - 是，dd[i]+=1
    - 否，退出遍历

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = 0
        d = dict()
        dd = dict()

        for c in chars:
            if c in d:d[c] += 1
            else:d[c] = 0
            dd[c] = 0
            
        for word in words:
            flag = True
            for w in word:
                if w in d:
                    if dd[w] > d[w]:
                        flag = False
                        break
                    dd[w] += 1
                else:
                    flag = False
                    break
            if flag:
                res += len(word)
            for i in dd:
                dd[i] = 0
                
        return res
```