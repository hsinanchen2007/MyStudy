### 解题思路
word 长度大于chars 不累加
根据chars构建词典
word中包含的字符，加入到新的词典中，每次有字符， 计数减一，减为负数则跳到下一个word

### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        char_dic = {}
        for char in chars:
            char_dic.setdefault(char, 0)
            char_dic[char] += 1
        count = 0
        for word in words:
            if len(word) > len(chars):
                continue
            word_use_char_dic = {}
            tag = True
            for wchar in word:
                if wchar not in char_dic:
                    tag = False
                    break
                if wchar in word_use_char_dic:
                    word_use_char_dic[wchar] -= 1
                    if word_use_char_dic[wchar] < 0:
                        tag = False
                        break
                else:
                    word_use_char_dic[wchar] = char_dic[wchar] - 1
            if tag:
                count += len(word)
        return count
                    

```