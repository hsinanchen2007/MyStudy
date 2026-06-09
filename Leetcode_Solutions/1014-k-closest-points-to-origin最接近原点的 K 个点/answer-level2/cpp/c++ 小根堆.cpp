定义一个point的结构，重载运算符，然后全部丢到小根堆里面取出前k个即可

时间复杂度O(nlogn+klogn) 即O(nlogn)


```c++ []
class Solution {
public:
    struct point{
        int x,y;
        bool operator < (const point& res) const
        {
            return sqrt(x*x + y*y) > sqrt(res.x*res.x + res.y*res.y);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<point> q;
        for(int i = 0; i < points.size(); i++){
            point p;
            p.x = points[i][0];
            p.y = points[i][1];
            q.push(p);
        }
        vector<vector<int>> res;
        for(int i = 0; i < K; i++){
            res.push_back(vector<int>());
            res[i].push_back(q.top().x);
            res[i].push_back(q.top().y);
            q.pop();
        } 
        return res;
    }
};
```
