### 解题思路
字典存储，依次遍历。

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic={}
        for letter in s:
            if dic.get(letter):
                dic[letter]+=1
            else:
                dic[letter]=1
        for letter in t:
            if dic.get(letter):
                dic[letter]-=1
                if dic[letter]==0:
                    del dic[letter]
            else:
                return False
        return not dic
```

![image.png](https://pic.leetcode-cn.com/737d4303ac47a1ba6a593355d326cd0f603aa7a23f6148052fdd3c7d8c4b69f3-image.png)
