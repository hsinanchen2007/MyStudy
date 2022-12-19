### 解题思路
只需要按照题干要求解题即可，可以将题目分为以下几个子部分：


1. 分割单词，对每一行的单词单独处理
2. 为除最后一行以外的其他行分配空格
3. 为最后一行分配空格

分配空格可以使用空格所占空间space_left和空格数spaces的商和余数比较方便的求得。

### 代码

```python3
class Solution:
    def getLastString(self, cur_words, maxWidth):
        r = cur_words[0]
        for item in cur_words[1:]:
            r += ' '
            r += item
        r += ' ' * (maxWidth - len(r))
        return r
    def getString(self, maxWidth, cur_words, words_len):
        spaces = len(cur_words) - 1
        r = cur_words[0]
        if spaces == 0:
            return r + ' ' * (maxWidth - len(r))
        space_left = maxWidth - words_len
        base = space_left // spaces
        left_num = space_left % spaces
        cur_space = 0
        # print(left_num, base, cur_words, spaces, space_left)
        for item in cur_words[1:]:
            if cur_space < left_num:
                r += ' ' * (base + 1)
            else:
                r += ' ' * base
            r += item
            cur_space += 1
        return r
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        cur_len = len(words[0])
        words_len = len(words[0])
        r = []
        cur_words = [words[0]]
        for item in words[1:]:
            if cur_len + 1 + len(item) > maxWidth:
                r.append(self.getString(maxWidth, cur_words, words_len))
                cur_words = [item]
                cur_len = len(item)
                words_len = len(item)
            else:
                cur_words.append(item)
                cur_len += 1 + len(item)
                words_len += len(item)
        r.append(self.getLastString(cur_words, maxWidth))
        return r

```