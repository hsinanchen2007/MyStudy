题目相当于求解自底向上的最小路径和，此时就是一个标准的动态规划问题
思路：自底向上求解到当前位置的最小路径和，到顶即为到顶的最小路径和
1. 最后一层即为到达的路径和
2. 往上到每一位置的路径和为：triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);

``` C++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       if(triangle.empty()) return 0;
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
```