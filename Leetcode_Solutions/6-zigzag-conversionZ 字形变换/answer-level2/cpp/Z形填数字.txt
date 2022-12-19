### 解题思路
没有一开始就申请一个大数组 一点一点分配的 好像影响了性能```
### 代码

```cpp
class Solution {
public:
enum  Direct
{
    Down,//下
    Right, //右上
};
    string convert(string s, int numRows) {
            if (numRows == 1)
            return s;
        vector<vector<char>> res(numRows, vector<char>(1,0));
        int row = 0, col = 0;
        Direct direct = Down;
        for(int i=0;i<s.length();i++)
        {
            res[row][col] = s[i];
            if (direct == Down) {
                row++;
                if (row + 1 == numRows)
                    direct = Right;
            }
            else
            {
                row--;
                col++;
                if (i != s.length()-1) {
                    for (int i = 0; i < numRows; i++)
                    {
                        res[i].resize(res[i].size() + 1);
                    }
                }
                if (row == 0)
                    direct = Down;
            }
        }

        string s_result = "";
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                if (res[i][j] != 0) {
                    s_result += res[i][j];
                }
            }
        }
        return s_result;     
    }
};
```