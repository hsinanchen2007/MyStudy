### 解题思路
此题为前一题的进阶版本，在原先已排好序的数组中插入一个数组，应先判断数组插入的位置，此位置的前一个区间的左边界应小于插入数组的第一个元素，后一个应大于第一个元素（若前后都存在元素）
插入结束之后，合并区间
### 代码
···python3    
class solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        size = len(intervals)
        if size==0:                             #若原数组中无元素，直接插入并返回
            intervals.append(newInterval)
            return intervals
        else:                                   #若有元素，找到插入位置，应注意该位置是否是数组的最后一个位置
            i=0
            while i<size and intervals[i][0]<=newInterval[0]:
                i+=1
            if i == size:
                intervals.append(newInterval)
            else:
                intervals.insert(i,newInterval)
#插入结束，合并区间：分两种情况：（1）前一个区间的右边界大于后一个的左边界而小于其右边界
（2）大于后一个的右边界
        size +=1
        i = 0
        result = []
        while i < size - 1:
            if intervals[i][1] >= intervals[i + 1][0] or intervals[i][1] >= intervals[i + 1][1]:
                if intervals[i][1] >= intervals[i + 1][0]:
                    intervals[i + 1][0] = intervals[i][0]
                if intervals[i][1] >= intervals[i + 1][1]:
                    intervals[i + 1][1] = intervals[i][1]
            else:
                result.append(intervals[i])
            i += 1
        result.append(intervals[i])
        return result
```cpp 算法同上
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        if(size==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        else{
            int i=0;
            while(i<size&&intervals[i][0]<newInterval[0])
                i++;
            if(i==size)
                intervals.push_back(newInterval);
            else
                intervals.insert(intervals.begin()+i,newInterval);
        }
        size++;
        vector<vector<int>> result;
        int i=0;
        while (i<size-1) {
            if (intervals[i][1] >= intervals[i + 1][0]||intervals[i][1]>=intervals[i+1][1]){
                if(intervals[i][1] >= intervals[i + 1][0])
                    intervals[i + 1][0] = intervals[i][0];
                if(intervals[i][1]>intervals[i+1][1])
                    intervals[i+1][1]=intervals[i][1];
            }
            else
                result.push_back(intervals[i]);
            i++;
        }
        result.push_back(intervals[i]);
        return result;
    }
};
```