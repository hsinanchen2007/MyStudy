### 解题思路
1. 分别获取到word1和word2在words里出现地方的索引；
2. word1的每一个索引和word2的每一个索引做减法，绝对值是相差位置；
3. 返回最小的那个差值绝对值；

没想到难度中等的题好像也没有很难，反而有些难度简单不那么简单；

进步空间在于时间复杂度上；

![image.png](https://pic.leetcode-cn.com/f7e307080253850a0207f91b7b92f3e0c79e64fdc6639cd4914dec4cc5851ab6-image.png)


### 代码

```python3
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        indice1 = []
        indice2 = []
        for i in range(len(words)):
            if words[i] == word1:
                indice1.append(i)
            if words[i] == word2:
                indice2.append(i)
        
        subRes = []
        for i in range(len(indice1)):
            for j in range(len(indice2)):
                subRes.append(abs(indice1[i] - indice2[j]))
        
        return min(subRes)

            
```