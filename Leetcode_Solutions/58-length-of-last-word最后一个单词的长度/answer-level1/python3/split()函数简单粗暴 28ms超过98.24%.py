### 解题思路
1、用split()函数将单词按空格分割成只有单词的list。
2、选取列表的最后一个元素，即最后一个单词。可借用len(list)函数获得list的长度，进而获得最后一个元素。
3、len()函数获得最后一个元素长度。
如图，简单粗暴。
### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
            a = s.split()
            if len(a) == 0:
                return 0
            else:
                l = len(a)
                return len(a[l-1])
        
        
        
```