### 解题思路
先把每个单词都翻转，然后构建前缀树。最后，遍历整棵树，统计单词，最终结果上每个单词+1.

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        for i in range(len(words)):
            words[i] = words[i][::-1]
        
        dic = {}
        for string in words:
            cur = dic
            for c in string:
                if c not in cur.keys():
                    cur[c] = {}
                cur = cur[c]
        
        # print(dic)
        res = []
        def digui(tmp_dic,tmp_s):
            for k in tmp_dic.keys():
                if tmp_dic[k] == {}:
                    res.append(tmp_s+k)
                else:
                    digui(tmp_dic[k],tmp_s+k)
        digui(dic,"")
        # print(res)
        
        count = 0
        for c in res:
            count += (len(c)+1)
        
        return count
```