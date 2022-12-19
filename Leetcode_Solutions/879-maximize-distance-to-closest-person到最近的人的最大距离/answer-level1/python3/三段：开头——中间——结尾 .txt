### 解题思路
首先要明确，如果座位在中间，即所找位置前后都有人坐了，那么这个最大值为(后面一个占座位-前面一个占座位)//2，与之区分的是首尾的情况，首尾无需除以2，直接第一个占座位-0或者数组长度-最后一个占座位
那么我们的算法：
1.遍历一遍，得到所有”1“位置的序号，存在一个数组中
2.遍历上述数组，获得前后序号两两之差，这个差除以2就是所求”最大距离“
3.另外计算首尾两种情况的”最大距离“
4.返回2、3步骤的最大值

### 代码

```python3
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        occupied=[i for i in range(len(seats)) if seats[i]==1] 
        maxs=[occupied[i+1]-occupied[i] for i in range(len(occupied)-1)]
        if len(occupied)==1:    #只有一个”1“时，没有mid这一情形
            mid=0
        else:
            mid=(max(maxs))//2
        start=occupied[0]
        end=len(seats)-occupied[-1]-1
        return max(mid,start,end)
        


```