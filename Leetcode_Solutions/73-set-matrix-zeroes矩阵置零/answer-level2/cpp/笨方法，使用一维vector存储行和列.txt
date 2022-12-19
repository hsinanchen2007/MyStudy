使用了push_back，可能这就是导致运行慢的原因，然后如果一行有多个0或者一列有多个0，会重复，可能好方法是使用不重复的存储方法，保证行和列各有唯一性，在设置0的时候也可以节省时间了
```
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();//n表示行数，m表示列数
        vector<int> a;//初始化一个vector用于存储为0的行和列
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    a.push_back(i);
                    a.push_back(j);
                }
            }
        }
        int l = a.size();
        for (int i = 0; i < l; ++i)
        {
            if (i % 2)//存储的行的a的下标是偶数
            {
                for (int j = 0; j < n; ++j)
                {
                    matrix[j][a[i]] = 0;//for循环设置0
                }
            }
            else//存储的列的a的下标是奇数
            {
                for (int j = 0; j < m; ++j)
                {
                    matrix[a[i]][j] = 0;
                }
            }
        }
        return;
    }
};
```