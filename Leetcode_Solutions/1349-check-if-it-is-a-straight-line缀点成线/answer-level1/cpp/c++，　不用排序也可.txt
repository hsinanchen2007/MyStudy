### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.empty() || coordinates[0].empty()) {
            return false;
        }
        if (coordinates.size() == 1) {
            return true;
        }
        // sort(coordinates.begin(), coordinates.end(), [](const vector<int>& a, const vector<int>& b) {
        //     if (a[0] != b[0]) {
        //         return a[0] < b[0];
        //     }
        //     return a[1] < b[1];
        // } );
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); ++i) {
            int y = coordinates[i][1] - coordinates[i - 1][1];
            int x = coordinates[i][0] - coordinates[i - 1][0];
            if (dy == 0) {
                if (y != 0) {
                    return false;
                }
            } else {
                if (dy * x != y * dx) {
                    return false;
                }
            }
        }
        return true;
    }
};
```