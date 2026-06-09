### 解题思路
参考84（栈）

### 代码

```cpp
class Solution {
public:
    int calc_max_square(vector<int> &heights){
        if(heights.empty()) return 0;
        stack<int> s;
        int n = heights.size();
        int rt = 0;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                int tmp = s.top();
                s.pop();
                if(s.empty()) rt = max(rt, i * heights[tmp]);
                else rt = max(rt, (i-s.top()-1) * heights[tmp]);
            }
            s.push(i);
        }
        return rt;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n+1, 0);
        int rt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            rt = max(rt, calc_max_square(heights));
        }
        return rt;
    }
};
```