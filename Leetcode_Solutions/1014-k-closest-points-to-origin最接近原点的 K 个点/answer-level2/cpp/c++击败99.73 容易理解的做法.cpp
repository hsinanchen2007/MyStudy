### 解题思路
与其他题解不同的是，本题没有使用大根堆去解决这个问题。
vector<pair<int,int>>tem;第一个int 代表point的位置，第二个代表每个point和原点的距离。
对tem进行排序。再根据第一个int point的位置插入到结果中。
![image.png](https://pic.leetcode-cn.com/0f598758790a51af31312ec6bd9317f1e0138f61a290b041aeccc520d6d5099b-image.png)

### 代码

```cpp
class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second < b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int size = points.size();
        vector<pair<int,int>>tem;
        for(int i = 0;i < size;i++)
        {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            tem.push_back(make_pair(i,dis));
        }
        sort(tem.begin(),tem.end(),cmp);
        vector<vector<int>> ans;
        for(int i = 0;i < K;i++)
        {
            ans.push_back(points[tem[i].first]);
        }
        return ans;
    }
};
```