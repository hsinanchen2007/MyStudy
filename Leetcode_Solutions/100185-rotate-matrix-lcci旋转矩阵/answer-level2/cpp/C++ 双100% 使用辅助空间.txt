
![image.png](https://pic.leetcode-cn.com/d9a29e6ff1b5dd2bf87e3ff4f1a106511342dd995c30fa40b2cf41f8be51cadf-image.png)

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(),vector<int>(matrix.size()));
        for(int i = 0;i < matrix.size();++i)
        {
            int y = matrix.size()-1-i;
            for(int j= 0;j < matrix.size();++j)
                temp[j][y] = matrix[i][j];
        }
        matrix = temp;
    }
};
```