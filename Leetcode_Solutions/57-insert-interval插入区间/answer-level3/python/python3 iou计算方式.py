### 解题思路
四种情况：
newInterval 插入空列
newInterval 插入序列前
newInterval 插入序列后
newInterval 插在序列中，计算iou

### 代码

```python3

def intersection(a,b):
    left=max(a[0],b[0])
    right=min(a[1],b[1])
    if left>right:
        return 0
    else:
        return right-left+0.01

def union(a,b):
    left=min(a[0],b[0])
    right=max(a[1],b[1])
    return right-left

def iou_cpu(a,b):
    return intersection(a,b)/union(a,b)

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if(len(intervals)==0):
            return [newInterval]
        new_intervals=[]
        start_ele=0
        end_ele=0
        iou_pre=0
        ele_pre=intervals[0]
        if(newInterval[1]<intervals[0][0]):
            new_intervals.append(newInterval)
        for ele in intervals:
            iou=iou_cpu(ele,newInterval)
            if(iou==0):
                new_intervals.append(ele)
            if(iou>0 and iou_pre==0):
                start_ele=min(ele[0],newInterval[0])
                end_ele=max(ele[1],newInterval[1])
                new_intervals.append([start_ele,end_ele])
            elif(iou>0):
                start_ele=min(ele[0],start_ele)
                end_ele=max(ele[1],end_ele)
                new_intervals[-1][0]=start_ele
                new_intervals[-1][1]=end_ele
            if(ele_pre!=ele and newInterval[0]>ele_pre[1] and newInterval[1]<ele[0]):
                new_intervals.insert(len(new_intervals)-1,newInterval)
            ele_pre=ele
            iou_pre=iou
        if(newInterval[0]>intervals[-1][1]):
            new_intervals.append(newInterval)
        return new_intervals
```