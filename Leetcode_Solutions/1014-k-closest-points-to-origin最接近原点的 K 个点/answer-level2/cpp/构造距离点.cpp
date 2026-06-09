### 解题思路
此处撰写解题思路

### 代码

```cpp
struct DistancePoint {
    int x;
    int y;
    DistancePoint(int a, int b){
        this->x = a;
        this->y = b;
    }
    friend bool operator < (const DistancePoint& t, const DistancePoint& other){
        return ((t.x * t.x) + (t.y * t.y)) > ((other.x * other.x) + (other.y * other.y));
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res = {};
        if (points.empty()) {
            return res;
        }
        priority_queue<DistancePoint, vector<DistancePoint>> kPoints;
        for (vector<int> point : points) {
            DistancePoint temp(point[0],point[1]);
            kPoints.push(temp);
        }
        for (int i=0; i < K; i++) {
            vector<int> temp;
            temp.emplace_back(kPoints.top().x);
            temp.emplace_back(kPoints.top().y);
            res.emplace_back(temp);
            kPoints.pop();
        }
        return res;
    }
};
```