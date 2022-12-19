### 思路一：哈希

### 代码

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int size = points.size();
        int res = 0;        
        for (int i = 0; i < size; ++i) {
           unordered_map<int, int> ump;
           for (int j = 0; j < size; ++j) {
               if (j == i) continue;
               int a = points[i][0] - points[j][0];
               int b = points[i][1] - points[j][1];
               ++ump[a * a + b * b];
           }
           for (auto it = ump.begin(); it != ump.end(); ++it) {
               res += it->second *(it->second - 1);
           }
        }
        return res;
    }
};
```