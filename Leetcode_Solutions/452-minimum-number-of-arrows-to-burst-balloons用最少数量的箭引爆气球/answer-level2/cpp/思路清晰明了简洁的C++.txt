该题的思路主要就是：先使用sort()排序，再从左往右看，依次比较left和区间的左边
也就是看看有没有重叠区域，有一个就算一个，算上之后记得让
left = min(points[i][1],left);相当于把这个重叠了的区间去掉
最终，区间数-重叠数即为所求。
```
代码块class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.empty())
            return 0;
        sort(points.begin(),points.end());

        int n = points.size();
        int count = 0;
        int left = points[0][1];

        for(int i = 1; i < n; i++)
        {
            if(points[i][0] <= left)
            {
                count++;
                left = min(points[i][1],left);
            }
            else
                left = points[i][1];
        }
        return (n-count);
    }
};
```
