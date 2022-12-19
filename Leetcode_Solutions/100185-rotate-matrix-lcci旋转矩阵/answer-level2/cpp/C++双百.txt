### 解题思路
原地算法。从外圈到内圈，转圈移动。
错误：一直把变换的下标弄错。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        double a=matrix.size();
        for(double i=0;i<(a/2);i++)
        {
            int tmp;
            for(int j=i;j<a-i-1;j++)//(i...a-1-i)
            {
                tmp=matrix[i][j];
                //cout<<matrix[i][j]<<"?"<<matrix[a-i-1-j][i];
                matrix[i][j]=matrix[a-1-j][i];//cout<<i<<j<<matrix[i][j]<<" ";
                matrix[a-1-j][i]=matrix[a-i-1][a-1-j];//cout<<matrix[a-i-1-j][i]<<" ";
                matrix[a-i-1][a-1-j]=matrix[j][a-i-1];//cout<<matrix[a-i-1][a-i-1-j]<<" ";
                matrix[j][a-i-1]=tmp;//cout<<matrix[j][a-i-1]<<" ";
            }
        }
    }
};
```