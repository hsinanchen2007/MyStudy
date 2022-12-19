### 解题思路
思路就是在词汇表中构建一个hash表，对于组成的单词而言，如果存在hash表中，就减去一，如果遇到的字母不存在hash表，或者hash表对应单词的计数为0，则不可能组成这个单词，如果能组成这个单词，我们就在结果res中添加这个单词，最后返回，算是用了hash的思想和结合生活实际吧。

### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        hash_table={}
        for i in chars:
            hash_table[i]=0
        for i in chars:
            hash_table[i]+=1
        res=[]
        for i in words:
            tmp=hash_table.copy()
            flag=0
            for j in i:
                if j not in tmp or tmp[j]==0:
                    flag=1
                    break
                elif j in tmp and tmp[j]>0:
                    tmp[j]-=1
            if not  flag:
                res+=i
        return len(res)
```