### 解题思路
此处撰写解题思路
![2020-04-07 12-58-43 的屏幕截图.png](https://pic.leetcode-cn.com/75d48932e5174b8095247d2542a1ec604abbd8e90a96ecf4ee9505a268e8af6a-2020-04-07%2012-58-43%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int M = 0;
        int N = matrix.size() - 1;
        
        while (M < N)
        {
            for (int i = M; i < N;) {
                for (int j = N; j > M;) {
                    int temp = matrix[M][i];
                    matrix[M][i] = matrix[j][M];
                    matrix[j][M] = matrix[N][j];
                    matrix[N][j] = matrix[i][N];
                    matrix[i][N] = temp;
                    i++;
                    j--;
                }
            }

            M++;
            N--;
        }
    }
};
```