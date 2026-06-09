### 解题思路
c[i, j] = min(c[i+1, j], c[i+1, j+1]) + tri[i, j];

### 代码

```cpp
class Solution {
public:
    int cala(int k1, int k2){
        int k = (k1*(k1+1)) / 2 + k2;
        return k;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        if(m == 0 || n == 0) return 0;
        int c[(m*(m+1)/2)];
        for(int i = m-1; i >= 0; i--){
            c[cala(m-1, i)] = triangle[m-1][i];
        }
        for(int i = m-2; i >= 0; i--){
            for(int j = triangle[i].size()-1; j >= 0; j--){
                c[cala(i,j)] = min(c[cala(i+1, j)], c[cala(i+1, j+1)]) + triangle[i][j];
            }
        }
        return c[0];
    }
};
```