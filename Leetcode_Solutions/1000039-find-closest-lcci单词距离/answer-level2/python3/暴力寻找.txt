### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/2bb79b132f902ca3d51a427eeba885a6efc1e84ae530ab0b8c5e9dea8e1bc5fe-%E6%8D%95%E8%8E%B7.PNG)
找到word1就将下表赋值给n1，找到word2就将下标赋值给n2，作差得到距离，不断寻找更新距离，一直取最小的距离，不用浪费空间去用数组储存多余的距离

### 代码

```python3
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        distance = distance1 = n1 = n2 = 0
        for i in range(len(words)):
            if words[i] == word1:
                n1 = i
            elif words[i] == word2:
                n2 = i
            else:
                continue
            if words[n1] == word1 and words[n2] == word2:#防止刚刚赋一个值后两个距离最小
                distance1 = abs(n2 - n1)
            if distance == 0:
                distance = distance1
            elif distance1 < distance:
                distance = distance1
        return distance
```