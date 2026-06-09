### 解题思路
和<56区间合并>的应用
1.创建区间列表
2.区间合并
3.求合并后的每个区间的差值之和

### 代码

```python3
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        #<56区间合并>的变形：创建区间列表，然后再合并区间，最后求合并后的每个区间的差值之和
        #创建区间
        intervals=[]
        for item in timeSeries:
            intervals.append([item,item+duration])
        #区间合并
        merged=[]
        intervals.sort(key=lambda x: x[0])#排序
        itvlen=len(intervals)
        for i in range(itvlen):
            if not merged or merged[-1][-1]<intervals[i][0]:#不相交
                merged.append(intervals[i])
            else:#相交，更改右端点
                merged[-1][-1]=max(merged[-1][-1],intervals[i][-1])
        #print(merged)
        sums=0
        for item in merged:
            sums+=item[1]-item[0]
        return sums

```