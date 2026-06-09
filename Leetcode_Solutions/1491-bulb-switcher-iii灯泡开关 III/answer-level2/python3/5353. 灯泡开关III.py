### 解题思路
时间复杂度为O(N)，主要思路就是要向所有的灯都变成蓝色，很明显第一盏灯必须开着，其次到开着的最右边的那盏灯，中间的灯也必须开着。

### 代码

```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        length = len(light)
        count = 0
        on_count = 0
        last_on = 0
        first_on = length+1
        for val in light:
            on_count += 1
            last_on = max(val,last_on) #最右边开着的灯
            first_on = min(val,first_on) #最左边开着的灯
            if last_on-first_on+1==on_count and first_on==1:  # 第一盏灯开着，并且中间的灯都是开着
                count+=1
        return count
```