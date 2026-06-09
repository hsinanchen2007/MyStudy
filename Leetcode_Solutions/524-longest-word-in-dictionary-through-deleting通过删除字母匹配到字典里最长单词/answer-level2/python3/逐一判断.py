# 成绩（2019.05.09）

执行用时 : 248 ms, 在Longest Word in Dictionary through Deleting的Python3提交中击败了77.99% 的用户

内存消耗 : 14.3 MB, 在Longest Word in Dictionary through Deleting的Python3提交中击败了93.88% 的用户

# 思路

没有用很巧妙的方法，就是逐一判断s是否能匹配d中的元素，然后同时记录可以匹配的元素的索引和长度。

判断上就是简单地遍历s中的字母，能够按次序和d中的元素吻合地话就返回True，否则False

最后返回结果时用了python的sorted函数还有list.index的特性，前者会对字符串列表按字典顺序排序，后者则是返回列表中该元素出现的第一个索引。

return时也用了一个很长的表示方法，这样节省内存也快一些。（但是可读性就会差很多）

# 可能的改进方向

- 判断是否能匹配的方法

sorted已经是python内置很快的函数了，我不太觉得可以写出来更快的排序方法

```python
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        
        def consist(long, short):
            m, counter = len(short), 0
            for i in long:
                if i == short[counter]:
                    counter += 1
                    if counter == m:
                        return True
            return False
        
        
        d, index, length = sorted(d), [], []
        for i, v in enumerate(d):
            if consist(s, v):
                index.append(i)
                length.append(len(v))
        if len(index) == 0:
            return ""
        else:
            return d[index[length.index(max(length))]]
```