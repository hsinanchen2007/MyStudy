额外的空间也可以不使用，但是要修改原数据，不太好，所以就用了额外的 n*sizeof(int)的空间。
line用于记录n层到n-1层最短的路径长度，其初始值为triangle的第n行。其递归公式为：
$$
line[j] = triangle[i][j] + min(line[j], line[j + 1])，i 表示当前自下向上到达第 i 层。
$$

```c
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> line(triangle[n - 1]);
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                line[j] = triangle[i][j] + min(line[j], line[j + 1]);
        return line[0];
    }
};
```