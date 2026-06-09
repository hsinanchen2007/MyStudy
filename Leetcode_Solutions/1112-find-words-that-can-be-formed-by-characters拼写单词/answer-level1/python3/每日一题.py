### 解题思路
如代码中的注释：

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        # 计数工具
        len_word = 0
        # 遍历所有单词
        for word in words:
            # 初始chars字符串，目的是为了每次重新遍历，list_str值重置
            list_str = list(chars)
            # 遍历单词中的字母
            for key in word:
                # 判断当前字母是否在chars字符中
                if key in list_str:
                    # 若字符串中存在当前字符则，删除当前字符
                    list_str.pop(list_str.index(key))
                else:
                    # 若当前字符不存在字符串中，则跳出循环
                    break
            # 顺利完成for循环，证明可以学习整个单词，则在技术工具中增加当前单词的字符数
            else:
                len_word += len(word)
        # 返回所有字符数
        return len_word
                
```