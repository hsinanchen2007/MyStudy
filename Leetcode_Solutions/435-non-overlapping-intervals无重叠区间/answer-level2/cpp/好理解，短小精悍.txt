```
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        //若向量为空，则返回0
        if(intervals.empty())
            return 0;

        //长度记为n
        int n = intervals.size();

        //排序
        sort(intervals.begin(), intervals.end());
        
        //从最左边的区间的右边开始
        int left = intervals[0][1];
        int count = 0;

        for(int i = 1; i < n; i++)
        {
            //每个区间的左边和left比较，left大，则count自增1
            if(intervals[i][0] < left)
            {
                count++;
                //当删除了一个区间，即这个区间对该题就无影响了，因此left要取尽小值
                left = min(left, intervals[i][1]);
            }
            else
                //每次left也在右移
                left = intervals[i][1];
        }
        return count;
    }
};
```
