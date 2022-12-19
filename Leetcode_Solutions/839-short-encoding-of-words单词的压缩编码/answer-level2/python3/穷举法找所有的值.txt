### 解题思路
先将列表的元素按照长度进行排序，然后从前往后遍历，比较前面的那个字符是否与后面的某个字符的尾部一样，如果一样就把它的index记下来，然后找下一个，直到把所有的需要删除的都找到，再遍历一遍，统计未被删除的元素的总长度再加上剩余的元素个数，就得到了结果。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=len)
        del_index = []
        num = 0
        for i in range(len(words)):
            if i == len(words)-1:
                break
            for j in range(i+1,len(words)):
                if words[i] == words[j][-len(words[i]):]:
                    del_index.append(i)
                    break
        for i in range(len(words)):
            if i not in del_index:
                num = num + len(words[i])
        num = num + len(words) - len(del_index)
        return num
```