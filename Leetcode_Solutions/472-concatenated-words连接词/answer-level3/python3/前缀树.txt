1. 所有单词按长度从大到小排序。
2. 定义一棵前缀树，这里用字典pre_dict实现。
3. 从长度最短的单词开始，检查此单词是否能用前缀树中的单词组成，如不能，则把此单词插入前缀树。

```python []

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        def check_word(word, pre_dict):
            if len(word) == 0:
                return True
            cur_dict = pre_dict
            for index, c in enumerate(word):
                cur_dict = cur_dict.get(c, None)
                if cur_dict is None:
                    return False
                if cur_dict.get('end', 0) == 1:
                    # 当前字符串前缀与树中单词匹配，递归搜索
                    if check_word(word[index+1:], pre_dict):
                        return True
            return False
        
        words.sort(key=lambda x: len(x))
        ans = []
        pre_dict = {}
        for item in words:
            if len(item) == 0:
                continue
            if check_word(item, pre_dict):
                ans.append(item)
            else:
                # insert word
                cur_dict = pre_dict
                for c in item:
                    if cur_dict.get(c, None) is None:
                        cur_dict[c] = {}
                    cur_dict = cur_dict.get(c)
                cur_dict['end'] = 1
        return ans
```
