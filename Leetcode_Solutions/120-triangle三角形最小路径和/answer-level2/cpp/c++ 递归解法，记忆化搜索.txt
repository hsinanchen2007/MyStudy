```
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) {
memo = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), -1));
return recursion(triangle, 0, 0);
}
int recursion(vector<vector<int>>& triangle, int i, int j) {
if (i == triangle.size() - 1) return triangle[i][j];
if (memo[i][j] == -1) {
int a = recursion(triangle, i + 1, j);
int b = recursion(triangle, i + 1, j + 1);
memo[i][j] = min(a, b) + triangle[i][j];
}
return memo[i][j];
}
vector<vector<int>> memo;
};
```
