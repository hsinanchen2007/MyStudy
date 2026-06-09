### 解题思路
**（1）整体思路**
**首先,**
做一个列宽为len(word1)+1，行宽为len(word2)+1的grid
首列为0,1...,len(word1)
首行为0，1...,len(word2)
grid其余值为0
**其次，**
在for循环的帮助下，依次计算并赋予grid[i][j]值，使
grid[i][j] 代表word1前i位的元素转换成word2前j位元素所需要的最短距离
**最后，**
grid[-1][-1]值 即为将word1转换成word2所使用的最短距离（最少步数）
如word1 = 'horse', word2 = 'ros',那么grid[-1][-1] = grid[5][3]

**（2）三种操作的说明**
"插入一个字符"
"删除一个字符"
"替换一个字符"
当word1[i-1] == word2[j-1]时，grid[i][j] = grid[i-1][j-1]；
当word1[i-1] != word2[j-1]时，grid[i][j] = min(grid[i-1][j-1], grid[i-1][j], grid[i][j-1]) + 1
其中，grid[i-1][j-1]表示替换操作，grid[i-1][j]表示删除操作，grid[i][j-1]表示插入操作
**例如：**
以word1为 'horse'，word2为'ros'，且grid[5][3]为例，即要将word1的前 5 个字符转换为 word2的前3个字符，也就是将horse转换为 ros，因此有：
(1) grid[i-1][j-1]，即先将word1的前4个字符hors转换为word2的前2个字符ro，然后将第五个字符word1[4]（因为下标基数以 0 开始）由e替换为s（即替换为word2的第三个字符，word2[2]）
(2) grid[i][j-1]，即先将word1的前5个字符horse转换为word2的前2个字符ro，然后在末尾补充一个s，即插入操作
(3) grid[i-1][j]，即先将word1的前4个字符hors转换为word2的前3个字符ros，然后删除word1的第5个字符



### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        num1 = len(word1)
        num2 = len(word2)
        grid = [[0]*(num2+1) for i in range(num1+1)]
        for i in range(num1+1):
            grid[i][0] = i
        for j in range(num2+1):
            grid[0][j] = j
        for i in range(1,num1+1):
            for j in range(1,num2+1):
                if word1[i-1] == word2[j-1]:
                    grid[i][j] = grid[i-1][j-1]
                else:
                    grid[i][j] = min(grid[i-1][j-1],grid[i-1][j],grid[i][j-1])+1
        return grid[-1][-1]
```