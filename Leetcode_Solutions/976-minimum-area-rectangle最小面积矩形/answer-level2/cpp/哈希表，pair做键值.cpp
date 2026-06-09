```cpp
class Solution {
public:
    // 要使pair能作为unordered_map的键值，需加这个
    struct hashfunc {
        template<typename T, typename U>
        size_t operator()(const pair<T, U> &x) const {
            return hash<T>()(x.first) ^ hash<U>()(x.second);
        }
    };
    
    int minAreaRect(vector<vector<int>>& points) {
        // 哈希表存点 
        unordered_map<pair<int,int>, int, hashfunc> m;
        for (auto & point : points ) {
            m[make_pair(point[0],point[1])]++;
        }
        
        int res = INT_MAX;
        // 遍历取两点，看能否成为矩形对顶点，若能,记录面积
        for (int i = 0; i < points.size()-1; i++) {
            for (int j = i+1; j < points.size(); j++) {
                int x1 = points[i][0],y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                if (x1!=x2 && y1!=y2 && m.find(make_pair(x1,y2)) != m.end() && m.find(make_pair(x2,y1)) != m.end()) {
                    res = min(res,abs((x1-x2)*(y1-y2)));
                }
            }
        }
        
        return res==INT_MAX?0:res;
    }
};
```
