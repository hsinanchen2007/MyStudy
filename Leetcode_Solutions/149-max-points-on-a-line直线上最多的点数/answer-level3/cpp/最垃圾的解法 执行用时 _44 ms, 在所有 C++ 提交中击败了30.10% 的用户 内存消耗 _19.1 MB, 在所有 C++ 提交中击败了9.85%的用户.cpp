### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2)
            return points.size();
        vector<vector<long>> lpoints;
        //转换成长整形
        for (int i = 0; i < points.size(); i++)
        {
            vector<long> ltemp;
            ltemp.push_back(long(points[i][0]));
            ltemp.push_back(long(points[i][1]));
            lpoints.push_back(ltemp);
        }
        //去重
        vector<vector<long>> x;
        vector<int> num;
        for (int i = 0; i < lpoints.size(); i++)
        {
            if (find(x.begin(), x.end(), lpoints[i]) != x.end())
                continue;
            vector<long> tt;
            tt.push_back(long(lpoints[i][0]));
            tt.push_back(long(lpoints[i][1]));
            x.push_back(tt);
            int w = 1;
            for (int j = i + 1; j < lpoints.size(); j++)
                if (lpoints[j] == lpoints[i])
                    w++;
            num.push_back(w);
        }

        if (x.size() == 2)
            return num[0] + num[1];
        else if (x.size() == 1)
            return num[0];

        int max = num[0];
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = i + 1; j < x.size() - 1; j++)
            {
                int res = cal(x[i], x[j], i, j + 1, x, num);
                if (res > max)
                    max = res;
            }
        }
        return max;
    }
    int cal(vector<long> a, vector<long> b, int ss, int s, vector<vector<long>>& points, vector<int> num)
    {
        int result = num[ss] + num[s - 1];
        long k1 = 0;
        long k2 = 0;
        k1 = (b[1] - a[1]);
        k2 = (b[0] - a[0]);
        for (int i = s; i < points.size(); i++)
        {
            if (((points[i][0] - a[0] != 0) && (points[i][1] - a[1]) * k2 == (points[i][0] - a[0]) * k1)
                || (points[i][0] == a[0] && points[i][1] == a[1])
                || (points[i][0] == b[0] && points[i][1] == b[1])
                || (points[i][0] == a[0] && points[i][0] == b[0] && a[0] == b[0]))
                result = result + num[i];
        }
        return result;
    }
};
```