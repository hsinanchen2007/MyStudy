### 解题思路
此处撰写解题思路

### 代码

```

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        ##换一个思路：先找出能够一直排序的，然后用数组的长度-能排序的长度就是需要删除的长度
        lens = len(intervals)
        ##特殊情况
        if lens==0:
            return 0
        
        ##贪心算法：先对每个数组值进行排序，按照末尾数字排序很重要
        intervals.sort(key=lambda x:x[1])
        print(intervals)
        pre = 0   ##记录前面一个可以连接的数组的下标位置
        nums = 1 ##记录有多少个可以连续连接在一起的数组,注意这里初始化为1，因为当有一个可以连续组合成为的时候，此时应该是2个，而不是1个数组，所以初始化应该是1，并且，单独的一个数组也能算作连续的
        for i in range(1,lens):
            if intervals[i][0]>=intervals[pre][1]:
                pre = i
                nums+=1
            else:
                pass
        return lens-nums ##剩下的就是不能连续组合的数组的个数
```