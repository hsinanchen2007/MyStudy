### 解题思路
先把列表去重，将列表用分隔符分开导入字符串，遍历字符串把如果元素出现多次的话把元素存入一个新列表
，把新列表里的元素从原列表里删除，最后连接原列表，并导出字符串长度即可

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words) -> int:
        words = list(set(words))#去重
        str1 = ""#中间长字符串
        ans = ""#目标字符串
        index = []#中间列表
        n = len(words)
        for i in range(n):#导出长字符串
            str1 += words[i] + "$"

        for j in range(n):#搜索在字符串中出现2次以上的元素并导入列表
            if str1.count(words[j] + "$") >= 2:

                index.append(words[j])

        for k in range(len(index)):#把index列表中元素从原列表中删除
            if len(words) == 1:
                break
            words.remove(index[k])

        for w in range(len(words)):#再连接，组成目标字符串
            ans += words[w] + "#"
        return len(ans)
