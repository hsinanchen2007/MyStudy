### 参考了@派大星星星星 @冯泡泡  两位的解法，感谢2位提供思路
此处撰写解题思路，本人菜鸡，不涉及对动态规划的空间压缩优化。膜拜大佬

思路1：自顶向下，递推公式  minPath[i][j] = Min()minPath[i-1][j-1], minPath[i-1][j]) + a[i][j], 
但显然要考虑特殊边界位置，即最左侧，最右侧位置是不同的。

自顶向下 做法
![image.png](https://pic.leetcode-cn.com/47647812c2a77e2b315fa772d330580aad0cbc1d7b1760c1ee537d229a05ea0d-image.png)
### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        /* 自顶向下，考虑边界条件要特殊处理 , minPath[i][j] = Min()minPath[i-1][j-1], minPath[i-1][j]) + a[i][j], 
        最左、右列要特殊处理
        最左： minPath[i][j] = minPath[i-1][j] + a[i][j]
        最右： minPath[i][j] = minPath[i-1][j-1] + a[i][j]
        */      
        int rowSize = triangle.size();
        vector<vector<int>> minPath(triangle);
        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        minPath[0][0] = triangle[0][0];
        minPath[1][0] = minPath[0][0] + triangle[1][0];
        minPath[1][1] = minPath[0][0] + triangle[1][1];
        
        for(int i=2;i<triangle.size();i++) {
            for(int j=0;j<triangle[i].size();j++) {
                                
                // 最左侧
                if(j==0)  minPath[i][j] = minPath[i-1][j] + triangle[i][j];
                // 最右侧
                else if(j==triangle[i].size()-1)  minPath[i][j] = minPath[i-1][j-1] + triangle[i][j];
                else  minPath[i][j] = min(minPath[i-1][j-1], minPath[i-1][j]) + triangle[i][j];                            
            }
        }
        // c++11新方法 max/ min_element 的使用请注意，不需要sort再打印了哦
        return *std::min_element(minPath[rowSize-1].begin(), minPath[rowSize-1].end() ) ;
    }
};


```

思路2： 自底向上 ，这种思路的好处是上面越来越小，没有边界的特殊处理

```cpp
        // 动态规划, 自底向上  递推式 dp[i][j] = min(dp[i+1][j], dp[i+1[j+1]) + triangle[i][j];
        int rowSize = triangle.size();
        vector<vector<int>> dp(triangle);
                
        for(int i=rowSize-2;i>=0;i--) {        
            for(int j=0; j<triangle[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
```


