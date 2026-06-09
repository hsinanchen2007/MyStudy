### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    /// <summary>
    /// 找到R之前先标记每个出现过的B或p，减少遍历次数
    /// </summary>
    /// <param name="board"></param>
    /// <returns></returns>
    public int NumRookCaptures(char[][] board)
    {
        int ans = 0;
        int[] colCountP = new int[8];//记录找到R之前每列上出现过的p或B
        for (int i = 0; i < 8; i++)
        {
            int rowCountP = 0;//记录找到R之前该行上出现过的p或B
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'R')//找到R之后
                {
                    for (int m = i + 1; m < 8; m++)//继续向下查找
                    {
                        if (board[m][j] == 'B' || board[m][j] == 'p')
                        {
                            ans += board[m][j] == 'p' ? 1 : 0;
                            break;
                        }
                    }
                    for (int m = j + 1; m < 8; m++)//继续向右查找
                    {
                        if (board[i][m] == 'B' || board[i][m] == 'p')
                        {
                            ans += board[i][m] == 'p' ? 1 : 0;
                            break;
                        }
                    }

                    //ans(找到R之后下方和右侧出现的p)
                    //colCountP[j](找到R之前上方出现过的p)
                    //rowCountP(找到R之前左侧出现过的p)
                    return ans + colCountP[j] + rowCountP;
                }
                else if (board[i][j] == 'B') //找到R之前出现过B，清空标记
                {
                    colCountP[j] = 0;
                    rowCountP = 0;
                }
                else if (board[i][j] == 'p') //找到R之前出现过p，添加标记
                {
                    colCountP[j] = 1;
                    rowCountP = 1;
                }
            }
        }
        return ans;
    }
}
```