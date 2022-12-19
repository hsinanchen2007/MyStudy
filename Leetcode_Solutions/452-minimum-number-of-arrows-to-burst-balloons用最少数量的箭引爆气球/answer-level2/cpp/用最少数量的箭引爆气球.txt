### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), CompareVec);
        //for(int i = 0; i < points.size(); ++i) {
        //    cout<<points[i][0]<<" "<<points[i][1]<<endl;
        //}
        int n = points.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        int res = 1;
        vector<int> pre = points[0];
        for(int i = 1; i < points.size(); ++i) {
            if (IsCross(pre, points[i])) {
                pre[0] = points[i][0];
                pre[1] = min(pre[1], points[i][1]);
            } else {
                ++res;
                pre = points[i];
            }
        }
        return res;
    }

    static bool CompareVec(vector<int>& vec1, vector<int>& vec2) {
        if (vec1[0] < vec2[0]) {
            return true;
        }else if (vec1[0] == vec2[0]) {
            return (vec1[1] <= vec2[1]);
        } else {
            return false;
        }
    }

    bool IsCross(vector<int>& vec1, vector<int>& vec2){
        return (vec2[0] <= vec1[1]);
    }
};
```