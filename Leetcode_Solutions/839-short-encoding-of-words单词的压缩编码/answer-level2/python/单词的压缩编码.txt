### 解题思路
自己对代码的一些理解都通过备注写在代码里了，记录一下方便自己今后复习

### 代码

```python
class Solution(object):
    def minimumLengthEncoding(self, words):
        #y = set('google')---> set(['e', 'o', 'g', 'l']
        group = set(words)
        #对于每一个单词
        for word in words:
            #检查所有后缀
            for k in range(1,len(word)):
                #将后缀存在在集合中的元素移除
                #set.discard(value) 若移除元素不在集合，do nothing
                group.discard(word[k:])
        #返回单词长度+1（#号）的求和
        return sum(len(word)+1 for word in group)
```