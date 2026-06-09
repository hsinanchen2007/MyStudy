## `filter()` 函数
+ 简单介绍一下`filter()`函数
+ 这个函数接收两个参数，第一个是一个函数，这个函数要求返回一个布尔变量。第二个是一个列表。
+ 然后对于列表的每一项，运行这个函数
+ 如果运行的结果是`True`，那么留下这一项，否则删掉
+ 即直观上的「筛选」过程。
+ 最后要转成`list`类型，否则是一个`filter`类型。
+ 举例而言`a = list(filter(lambda x: x % 2 == 1,[1,2,3]))`
+ 相当于把`[1,2,3]`这个列表所有的奇数提取出来，返回一个`[1,3]`

## 思路
+ 对于给定的列表的每一项进行筛选，返回那些通过筛选的列表，即一个非常标准的`filter()`函数
+ `return list(filter(function,words))`
+ 难点在于筛选的函数，即上面的`function`应该怎么写。
+ 我们将每一行作为一个集合，总共三个集合。
+ 对于传来的单词，我们也将它变成一个集合。
+ 如果这个集合是任一一个集合的子集，那么说明这个单词是可以用一行写出来的。
+ 即「对于每一个单词，如果这个单词的小写，是这三个集合中的任意一个，那返回True」。
+ 注意大小写的转换。
+ 如果没法理清的话，可以单独写一个函数。

## 代码
+ 一行的代码如下
```python
class Solution:
    def findWords(self, words: List[str]) -> List[str]:        
        return list(filter(lambda word: any(set(word.lower()).issubset(line) for line in [set('asdfghjkl'),set('qwertyuiop'),set('zxcvbnm')]),words))
```