## 首先写出暴力递归  但是会超出时间限制   题意等同于向下或向右下走
```
//暴力递归版本  会超时
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       return dfs(0, 0, triangle);
    }
    int dfs(int x, int y,vector<vector<int>>& triangle) {
        if (x == triangle.size() )
            return 0;
        return triangle[x][y] + min(dfs(x + 1, y, triangle),dfs(x + 1, y + 1, triangle));
    }
};

```
# dp版本  直接改原数组省事...  用搭积木方法填上去  不懂得自己看看怎么用暴力递归改动态规划
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                triangle[i][j] += min (triangle[i + 1][j + 1], triangle[i + 1][j]);
            }
        }
        return triangle[0][0];
    }
};

```


