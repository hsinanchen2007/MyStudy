### 解题思路
与前一题不一样的地方在于这里的矩阵不是方的，因此需要增加退出条件判断break

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix[0].empty()) return ans;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n-1;
        int top = 0, down = m-1;
        ans.resize(m*n);
        int cnt = 0;
        while(left <= right && top <= down){
            for(int i = left; i <= right; i++){
                ans[cnt++] = matrix[top][i];
            }
            top++;
            if(top > down) break;
            for(int i = top; i <= down; i++){
                ans[cnt++] = matrix[i][right];
            }
            right--;
            if(left > right) break;
            for(int i = right; i >= left; i--){
                ans[cnt++] = matrix[down][i];
            }
            down--;
            if(top > down) break;
            for(int i = down; i >= top; i--){
                ans[cnt++] = matrix[i][left];
            }
            left++;
            if(left > right) break;
        }
        return ans;
    }
};
```