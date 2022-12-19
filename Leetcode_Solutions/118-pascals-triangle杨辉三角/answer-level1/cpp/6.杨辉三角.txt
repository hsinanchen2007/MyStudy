### 解题思路
担心越界问题可以先处理边界
把三角形的每一行靠最左排列就能找到规律了不用那么麻烦的中位数啥的
现在想来大一实现的那个打印三角形也可以这样的愣是找了好复杂的规律，学会化简问题
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        //初始化以及处理边界
        for(int i=0;i<numRows;i++){
            ans[i]=vector<int>(i+1,0);
            ans[i][0]=1;
            ans[i][i]=1;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<ans[i].size()-1;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];//因为处理了边界所以不会越界
            }
        }
        return ans;
    }
};
```