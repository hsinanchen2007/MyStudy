根据youtube视频：https://www.youtube.com/watch?v=l3hda49XcDE 的算法思路编写
![image.png](https://pic.leetcode-cn.com/81b1fda4edc2f9ffa5a8991d1ac160840003e4c5e8231d1932ef04f00db8d908-image.png)
![image.png](https://pic.leetcode-cn.com/15485bf3573de0ac83082198e40c498e5d74f16bb09e3aa9e1407773335e48f6-image.png)
构造(len(text)+1)*(len(pattern)+1)的table用来存储text与pattern的子列是否match,最终输出table的最后一项即为所求。
```python []
class Solution(object):
    def isMatch(self, text, pattern):
        table = [[False]*(len(pattern)+1) for _ in range(len(text)+1)]
        table[0][0]=True
        for i in range(len(text)+1):
            for j in range(1,len(pattern)+1):
                first_match = i>0 and pattern[j-1] in (text[i-1],".")
                if j >= 2 and pattern[j-1]=="*":
                    table[i][j]=table[i][j-2] or table[i-1][j] and pattern[j-2] in (text[i-1],".")
                else:
                    table[i][j]=first_match and table[i-1][j-1]
        return table[len(text)][len(pattern)]   
```

