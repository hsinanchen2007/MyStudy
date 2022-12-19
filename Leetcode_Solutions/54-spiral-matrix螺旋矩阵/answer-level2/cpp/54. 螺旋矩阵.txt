### 直接做就是
背下来，面试的时候根本没这个心情来推各种边界，这个解是双100%
### 时间/空间复杂度
时间：O（mn）
空间：O（mn）
### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return {};
        int rows=matrix.size(),cols=matrix[0].size();
        int left=0,right=cols-1,top=0,bottom=rows-1;
        vector<int> res;
        while(true){
            for(int i=left;i<=right;++i) res.push_back(matrix[top][i]);
            if(++top>bottom) break;
            for(int i=top;i<=bottom;++i) res.push_back(matrix[i][right]);
            if(--right<left) break;
            for(int i=right;i>=left;--i) res.push_back(matrix[bottom][i]);
            if(--bottom<top) break;
            for(int i=bottom;i>=top;--i) res.push_back(matrix[i][left]);
            if(++left>right) break;
        }
        return res;
    }
};
```