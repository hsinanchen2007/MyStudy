### 解题思路
先把每一辆车到达终点需要的时间算出来：
`times = [(target-pos)/spe for pos, spe in zip(position, speed)]`

然后把各辆车的起始和预计到达终点的时间组合到一起
`res = [(i, j) for i, j in zip(position, times)]`

然后把res列表里的元组按照i，也就是初始位置的大小进行排序
`res.sort(key=lambda x:x[0]) `

到这里，我们会发现，当我们遍历`res`时，如果当前车辆i的用时比前面的车辆用时短或者相等的话，它们就会组成一个车队
即如果`res[i+1:]`中存在车辆到达终点的用时比`res[i]`更长，那`res[i]`必然会追上它，从而组成一个车队

根据以上描述，我们逆序遍历`res`，记录逆序遍历过程中的用时最大值`big`，如果当前车辆的用时大于`big`，那么这个车就是单独的一个车队。

### 代码

```python3
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        if len(position) == 1 or not position:
            return len(position)
        times = [(target-pos)/spe for pos, spe in zip(position, speed)]
        res = [(i, j) for i, j in zip(position, times)]
        res.sort(key=lambda x:x[0]) 
        count = 1
        big = res[-1][1]
        for i in range(len(res)-2,-1,-1):
            if res[i][1] > big:
                big = res[i][1]
                count += 1
                continue
        return count
```