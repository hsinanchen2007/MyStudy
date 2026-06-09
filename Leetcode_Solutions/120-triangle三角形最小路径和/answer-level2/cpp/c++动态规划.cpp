### 解题思路
**状态转换方程：**
- 第二行的两个元素值只能来自第一行，需要特殊处理
- 每行第一个元素的值只能来自他上方
- 每行最后一个元素的值只能来自他左上角
- 其他元素遵循：当前值=min(左上角的值,上方的值)
注意测试例子中会出现`[[-10]]`这种例子，需要对只有一行元素的二维数组特殊处理

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        if(triangle.size()==1) return triangle[0][0];
        triangle[1][0]+=triangle[0][0];
        triangle[1][1]+=triangle[0][0];
        for(int i=2;i<triangle.size();++i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                if(j==0) triangle[i][j]+=triangle[i-1][0];
                else if(j==triangle[i].size()-1) triangle[i][j]+=triangle[i-1][j-1];
                else triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        int res=1<<31-1;
        for(int t : triangle[triangle.size()-1])
        {
            res=min(res,t);
        }
        return res;
    }
};
```
