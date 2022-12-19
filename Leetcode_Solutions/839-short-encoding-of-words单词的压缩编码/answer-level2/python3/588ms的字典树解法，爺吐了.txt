### （1）字典树解法
Tire树，也称字典树，是一种专门处理字符串匹配的树形数据结构，常用来解决**在一组字符串集合中中快速查找某个字符串**的问题。Tire树的本质是**利用字符串之间的公共前缀，将重复的前缀合并在一起**。

本题字典树解法的基本思路为：
- 先去list按照字符串长度由长到短进行排序，避免em和emit都可以插入到Trie树这种情况
- 将每个字符串倒序，并插入到Trie树中
- 统计可以插入到Trie树中的字符串的长度


```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        length = 0
        tire = Tire()
        words.sort(key = lambda s: len(s),reverse = True)  # 根据字符串长短排序
        #print(words)
        for word in words: 
            length += tire.insert(word[::-1])
        return length

class Tire:
     ### 初始化，存储无意义字符（根节点root）
    def __init__(self):
        self._root = TrieNode("")  
        
	### 插入字符串
    def insert(self, text: str) -> None:  
        node = self._root
        is_new = False
        # 字符串text中的每个字符都调用lamda表达式，其中ord求ASCII值 
        for index, char in map(lambda x: (ord(x) - ord("a"), x), text):   
            if not node._children[index]:  # node._children[index] 为空，Trie树还没有该字符
                is_new = True
                node._children[index] = TrieNode(char) # 插入字符
            node = node._children[index] # ???
        if is_new:  
            return len(text) + 1  
        else: 
            return 0

class TrieNode:
    def __init__(self, data: str):
        self._data = data
        self._children = [None] * 26 
```

### （2）先翻转再排序
字典树解法真的又臭又长，比较容易理解的另一种解法是：
- 先对每个单词进行翻转，如`time,me,beil`变成了`emil,em,lieb`；
- 这时对字符串进行排序，如`emil,em,lieb`变成了`em,emil,lieb`；
- 当某个字符串是另一个字符串的前缀时，忽略，否则统计字符串长度


```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        length = len(words)
        #reversed_words = [word[::-1] for word in words]
        reversed_words = []
        for word in words:
            reversed_words.append(word[::-1])    # 反转每个word
        reversed_words.sort()  # 排序
        
        cnt = 0
        for i in range(length):
            if i+1 < length and reversed_words[i+1].startswith(reversed_words[i]):
                pass
            else:
                cnt += len(reversed_words[i]) + 1
        
        return cnt            
```
经测试，116ms,14M，还是挺香的


### （3）排序后直接搜索

```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key= lambda s: len(s),reverse=True)  # 由长到短排序
        wide_str= words[0]+'#'
        for i in words:
            if wide_str.find(i+'#') == -1:    # 该单词不在里面（#不可省，避免跨单词）
                wide_str = wide_str + i + '#'  # 添加到里面
            else:
                continue
        return len(wide_str)
```
