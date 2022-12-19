### 解题思路

maxS 表示当前最右方亮着的灯， curMinBlue 表示从最左边开始连续亮着的灯的最右边一个，
新打开一盏灯后，检查是否全蓝只用从 curMinBlue 到 maxS 就可以了,curMinBlue之前的都是开着的

### 代码

```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        ret = 0
        status = [0] * len(light)
        maxS = 0
        curMinBlue = 0
        for v in light:
            status[v - 1] = 1
            if v > maxS:
                maxS = v
            isAllBlue = True
            for i in range(curMinBlue,maxS):
                if status[i] == 0:
                    isAllBlue = False
                    break
            if isAllBlue:
                ret += 1
                if v > curMinBlue:
                    curMinBlue = v
        return ret
```