

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;

        for(auto m:matrix)
            if(find(m.begin(),m.end(),target)!= m.end()) return true;
        
        return false;
    }
};
```