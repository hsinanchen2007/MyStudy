### 解题思路
大家应该都很熟悉的杨辉三角，就是以前都是直接二维数组，现在二维vector废了点劲

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> shu;
        if(numRows == 0)return shu;
        int a[numRows][numRows] = {0};
        for(int i = 0; i < numRows; i++)
        {
            a[i][0] = 1;
            a[i][i] = 1;
            for(int j = 1; j < i; j++)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
            vector<int> shuai(a[i],a[i] + i + 1);
            shu.push_back(shuai);
        }
        return shu;
    }
};
```