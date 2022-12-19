### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先求逆矩阵，再转换为旋转矩阵

        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(n==0) return;

        //求逆矩阵
        for(int i=0; i<m; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                Swap(matrix[i][j],matrix[j][i]);
            }
        }

        //每一行的元素调整位置
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n/2; ++j)
            {
                Swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }

        return;
    }

    //Swap函数，原地交换，应用公式a^b^b=a, a^a^b=b
    void Swap(int& a, int& b)
    {
        a=a^b;
        b=a^b;
        a=b^a;
    }
};
```