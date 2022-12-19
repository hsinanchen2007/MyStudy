### 解题思路
![image.png](https://pic.leetcode-cn.com/194f5e1fb337407fcc3ec73941a08d408f3b5852ffd191f24e076efe278af36a-image.png)

由外到内，依次做循环的赋值：
![image.png](https://pic.leetcode-cn.com/e056b40ac1ffd4a338d891048902d1be79b0bd5f0599f9d2bf64e805976c7c3d-image.png)

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int n = (N + 1) / 2;
        for(int i = 0; i < n; i++)
            for(int j = i; j < N - i - 1; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 -j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = tmp;
            }
    }
};
```