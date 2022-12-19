### 解题思路
![2.png](https://pic.leetcode-cn.com/3a267c5da6f85425437f41a71ef457982373cb5cc3ab0d50cffd4842b8751759-2.png)
此处撰写解题思路

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        le = len(s)
        word_dict = {}
        for i in s:
            if i not in word_dict.keys():
                word_dict.setdefault(i, 1)
            else:
                word_dict[i] += 1
        while True:
            j = t[0]
            if j not in word_dict.keys():
                return j
            else:
                t = t.replace(j, '', word_dict[j])
                del word_dict[j]
            if len(t)==1:
                return t[0]
                
```