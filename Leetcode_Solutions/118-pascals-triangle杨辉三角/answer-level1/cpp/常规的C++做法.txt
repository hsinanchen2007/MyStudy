### 解题思路
动态规划，方程：` res[i].push_back(res[i-1][j-1]+res[i-1][j])`，注意只能用`push_back`函数来添加`res[i][j]`元素，直接用`res[i][j]=res[i-1][j-1]+res[i-1][j]`的话并不行
还是自己STL学的不太扎实。。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows);//二维数组
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){//第i行有i+1个元素
                if(j==0||j==i)
                    res[i].push_back(1);
                else
                    res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
        }
        return res;
    }
};
```