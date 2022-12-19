### 解题思路
设置四个围墙`left right top down`, 触墙转弯，同时当前贴着的墙回缩。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int left = 0, right = n-1;
        int top = 0, down = n-1;
        int cnt = 0;
        while(left <= right && top <= down){
            for(int i = left; i <= right; i++){
                mat[top][i] = ++cnt;
            }
            top++;
            for(int i = top; i <= down; i++){
                mat[i][right] = ++cnt;
            }
            right--;
            for(int i = right; i >= left; i--){
                mat[down][i] = ++cnt;
            }
            down--;
            for(int i = down; i >= top; i--){
                mat[i][left] = ++cnt;
            }
            left++;
        }
        return mat;
    }
};
```