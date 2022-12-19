### 解题思路
- 建立words中各个word与其出现次数的字典（哈希表）
- 建立滑窗在s中遍历，看滑窗内的字典和words字典是否一致

### 代码

```python3
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        word_len = len(words[0])
        words_num = len(words)
        words_len = word_len * words_num
        if words_len > len(s):
            return []

        dic = {}
        for i in words:
            if i in dic.keys():
                dic[i] += 1
            else:
                dic[i] = 1
        res = []
        for i in range(0, len(s)+1-words_len):
            tmp_dic = {}
            # 核心步骤
            # 统计窗口中的words的字典，与给定的words字典进行比较
            # 相等则说明s可以恰好由words串联成
            for j in range(words_num):
                cur = s[i+j*word_len: i+(j+1)*word_len]
                if cur in tmp_dic.keys():
                    tmp_dic[cur] += 1
                else:
                    tmp_dic[cur] = 1
            if dic == tmp_dic:
                res.append(i)
        return res

```
### PS： python中统计各元素的出现次数 建立字典，除了常规的遍历方法，也可以使用`collection`库中的`Counter()`函数: `dic = collection.Counter(list)`