### 思路

**最大编号**

```
遍历一遍，修改当前状态为开灯，并比较开灯次数是否等于记录的最大编号。
如果相等，表示灯可以变蓝，于是就计数 + 1。
```

**时间复杂度:** O(n)
**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        n = len(light)
        flag = [False] * (n+1)
        cnt_blue, cnt_light = 0, 0
        max_i = 0
        for i in range(n):
            flag[light[i]] = True  # turn on bulb开灯
            cnt_light += 1
            max_i = max(max_i, light[i])
            # 已开灯数量 = 当前记录的最大编号：灯变蓝计数 + 1
            if cnt_light == max_i:
                cnt_blue += 1
        return cnt_blue
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1375-Bulb-Switcher-III/1375.py)