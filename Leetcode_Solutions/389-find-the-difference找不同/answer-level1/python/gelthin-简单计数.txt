### 解题思路
简单计数然后遍历 t
想要使用花哨计数，但发现无法使用在这一个题目上。
与习题 [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/) 相似。


### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        num_str = [0]*26
        for x in t:
            num_str[ord(x)-ord('a')] += 1  # 计数索引
        for x in s:
            num_str[ord(x)-ord('a')] -= 1
        
        for x in t:  # 需要遍历整个数组
            if num_str[ord(x)-ord('a')]==1: # x 取 0 到 len(t)-1 都对
                return x
    
#### 下面是有错的代码，修改后仍有错，过不去测试样例 a, aa。
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        num_str = [-1]*26
        for i in range(len(t)):
            num_str[ord(t[i])-ord('a')] = 0  # 先变为 0 
            num_str[ord(t[i])-ord('a')] += i  # 花哨索引  注意到可能会有重复字符 s=a t=aa
        for x in s:
            num_str[ord(x)-ord('a')] = -1
        for x in num_str:  # 只需遍历 26
            if x != -1: # x 取 0 到 len(t)-1 都对
                return t[x]   
```