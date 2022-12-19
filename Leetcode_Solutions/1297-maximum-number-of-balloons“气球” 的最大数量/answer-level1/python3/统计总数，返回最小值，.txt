### 解题思路
统计所有b,a,l,o,n的数量
因为l,o在单词中出现两次，所以在最后的统计结果中分别除以2
列表中最小的值，即为能构成balloon的个数

### 实现代码
```
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        
        balloons = ['b', 'a', 'l', 'o', 'n']
        balloons_num = [0, 0, 0, 0, 0]
        for item in text:
            if item in balloons:
                index = balloons.index(item)
                balloons_num[index] += 1
        
        balloons_num[2] = int(balloons_num[2]/2)
        balloons_num[3] = int(balloons_num[3]/2)

        return min(balloons_num)
```
