### 解题思路
看了一下大佬的做法，第一次用zip函数以及set不重复的特点，很震撼，感觉自己很菜，感觉评论区很多做法，如果认真学习，一道题要做好几个小时……

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s=""
        for i in zip(*strs):
            if len(set(i))==1:
                s=s+i[0]
            else:
                break
        return s
```