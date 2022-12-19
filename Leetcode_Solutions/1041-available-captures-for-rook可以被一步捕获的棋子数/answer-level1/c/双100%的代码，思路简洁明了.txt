### 解题思路
双百分的代码哦，注释写的很清楚哦

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y; // "R"的坐标
        int sum = 0;  

        for (int i = 0; i < 8; i ++) //找到'R'的位置
            for (int j = 0; j < 8; j ++)
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                    break;
                }
        
        typedef pair <int, int> PII; //定义一个方向，这里因为只能在x，y的方向上移动，就开了一个pair数组
        PII a[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < 4; i ++){
            int m = x + a[i].first, n = y + a[i].second;
            if (m >= 0 && m < 8 && n >= 0 && n < 8 && board[m][n] == 'p')
            {
                sum ++;
                continue;
            } 
            while(m >= 0 && m < 8 && n >= 0 && n < 8 && board[m][n] == '.'){
                    m += a[i].first;
                    n += a[i].second;
                    if (m >= 0 && m < 8 && n >= 0 && n < 8 && board[m][n] == 'p')
                    {
                        sum ++;
                        continue;
                    } 
                }
    
        }
        return sum;
    }
};
```