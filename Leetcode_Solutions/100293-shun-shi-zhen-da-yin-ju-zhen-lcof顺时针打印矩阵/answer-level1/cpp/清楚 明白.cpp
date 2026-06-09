##### 直接模拟即可

![image.png](https://pic.leetcode-cn.com/bea8b92a89ed3fda6fd5931bd28b31f74516a674ddccc3572662ce6da12a10e3-image.png)

```C++ []
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        vector<int> ans;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while(u <= d && l <= r)
        {
            // 向右
            for(int i = l; u <= d && i <= r; i++)
                ans.push_back(matrix[u][i]);
            u++;
            
            // 向下
            for(int i = u; l <= r && i <= d; i++)
                ans.push_back(matrix[i][r]);
            r--;
            
            // 向左
            for(int i = r; u <= d && i >= l; i--)
                ans.push_back(matrix[d][i]);
            d--;
            
            // 向上
            for(int i = d; l <= r && i >= u; i--)
                ans.push_back(matrix[i][l]);
            l++;
        }
        return ans;
    }
```

**时间复杂度:**`O(M*N)` M、N为矩形的行数和列数
**空间复杂度:**`O(1)` 除开答案数组
