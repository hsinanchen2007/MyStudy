按Xstart坐标排序，如果points不空则至少需要一个，然后从第二个气球遍历。
贪心思想是击中前一个气球的情况下击中尽可能多的气球，如果不满足再增加弓箭数目同时将不满足的气球设为新的对比单位。
代码如下：
```
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);  // 按Xstart排序
        int ans = 1;  //  只要points不为空，则至少需要1；
        vector<int> prev = points[0];  // 记录上一个必须增添弓箭的射击区域
        for(int i = 0; i < points.size(); i++)  // 从第二个气球开始遍历
        {
            if(points[i][0] > prev[1])
            {
                ans++;
                prev = points[i];
            }
            else if(points[i][1] < prev[1]){
                prev = points[i];
            }
        }

        return ans;
    }

};
```
