### 解题思路
动态规划Dynamic Programming，可以直接在原数组上进行修改。参考了几位Cpp大佬的题解思路，还有一位用Python解题的大佬思路。一旦明白要求解的目标，其实很容易、也很快地想到如下解法。直接看代码。


### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划DP，可以直接在原数组上修改
        for(int i=0;i<grid.size();i++){//遍历行
            for(int j=0;j<grid[0].size();j++){//遍历列
                if(i==0&&j==0) continue;//注意cpp和python语法的不同，不能用i==j==0条件来判断
                else if(i==0) grid[i][j]+=grid[i][j-1];//对于第一行边界元素特殊处理，只能从左边的元素得到当前的最短路径和
                else if(j==0) grid[i][j]+=grid[i-1][j];//对于第一列边界元素特殊处理，只能从上面的元素得到当前的最短路径和
                else grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);//一般元素取其上面或左边元素的最小值
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
```


###复杂度分析：
时间复杂度 O(M x N) ：遍历整个grid数组。
空间复杂度 O(1) ： 直接在原数组上进行修改，因此没有使用额外空间。