### 解题思路
对于所有的单词，由题意可得当一个单词是某个单词的后缀时，则该单词被压缩，因此首先按words中单词的长度逆序排序，同时定义一个m_str来存储已压缩的字符串（初始为""），然后逐一的取出words中的单词，倘若当前取出单词是压缩串中的某个单词的后缀时，则将该单词忽略，判定的方法是：
- 利用字符串的find方法找到当前单词在压缩串中的开始位置index；
- 当index不为-1，即在压缩串中找到一个子串等于当前单词，并且m_str[index+len(item)]=='#'，即说明该单词是压缩串中某个单词的后缀。

否则将该单词加入到压缩串中，当前长度加上（当前单词长度+1）。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        m_str = ''
        length = 0
        words.sort(reverse = True,key = lambda x:len(x))
        for item in words:
            flag = 1
            index = m_str.find(item)
            if index != -1 and m_str[index+len(item)]=='#':
                flag = 0
            if flag == 1:
                m_str += item + '#'
                length += len(item) + 1
        return length
```