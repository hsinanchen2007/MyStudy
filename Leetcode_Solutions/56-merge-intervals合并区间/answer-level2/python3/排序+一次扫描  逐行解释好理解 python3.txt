# 题解
## 排序+一次扫描
 1. 特判，若$intervals$为空，返回$[]$。
 2. 定义数组长度$n$，当前合并区间$[left,right]$，初始化：$left=intervals[0][0],right=intervals[0][1]$
 3. 将$intervals$，按照左界进行排序。
 4. 从第二个区间开始遍历：
 	* 若下一区间$intervals[i]$的左界小于等于当前合并区间的右界，即$intervals[i][0]<=right$，表示有公共部分：
 		+ 此时，若满足$intervals[i]$的右界大于当前合并区间的右界，即$intervals[i][1]>right$，表示$intervals[i]$不包含于当前合并区间，需要更新当前合并区间的右界$right=intervals[i][1]$。
 	* 若下一区间$intervals[i]$的左界大于当前合并区间的右界，说明没有交集
 		+ 将当前合并区间$[left,right]$加入$res$。
 		+ 更新当前合并区间左界和右界，指向下一区间，即$left=intervals[i][0],right=intervals[i][1]$。
 5. 将最后一个合并区间加入$res$。
 6. 返回$res$。



### 复杂度分析
 - 时间复杂度：$O(N \log N)$，数组排序$O(N \log N)$，遍历数组$O\left(n\right)$，总体$O(N \log N)+O\left(n\right)$，$O(N \log N)$
 - 空间复杂度：$O(N)$，借助$res$保存结果

### Python

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if(not intervals):
            return []
        n=len(intervals)
        intervals.sort()
        res=[]
        left=intervals[0][0]
        right=intervals[0][1]
        for i in range(1,n):
            if(intervals[i][0]<=right):
                if(intervals[i][1]>right):
                    right=intervals[i][1]
            else:
                res.append([left,right])
                left=intervals[i][0]
                right=intervals[i][1]
        res.append([left,right])
        return res
```
### 另一种写法

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals=sorted(intervals)
        res=[]
        n=len(intervals)
        i=0
        while(i<n):
            left=intervals[i][0]
            right=intervals[i][1]
            while(i<n-1 and intervals[i+1][0]<=right):
                i+=1
                right=max(intervals[i][1],right)
            res.append([left,right])
            i+=1
        return res
```