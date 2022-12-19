### 解题思路
杨辉三角的结果是个下三角矩阵。每行第一个元素和最后一个元素都是1，其他元素是上一行对应位置和前一个位置元素的和。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i = 0, j = 1;

        for(; i<numRows; i++){
            vector<int> vec;
            vec.push_back(1);
            for(j=1; j<i; j++){
                vec.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            if(i == j){
                vec.push_back(1);
            }
            ans.push_back(vec);
        }

        return ans;
    }
};
```