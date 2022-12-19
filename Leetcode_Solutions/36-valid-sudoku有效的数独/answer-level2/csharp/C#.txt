哈希表思路,为每个元素所对应的行,列,宫 创建一个哈希表查重复
```
public bool IsValidSudoku(char[][] board)
    {
        if (board==null || board.Length==0 )
        {
            return false;
        }
        Dictionary<char, int>[] row = new Dictionary<char, int>[9];//行
        Dictionary<char, int>[] col = new Dictionary<char, int>[9];//列
        Dictionary<char, int>[] box = new Dictionary<char, int>[9];//宫
        //初始化哈希表
        for (int i = 0; i < 9; i++)
        {
            row[i] = new Dictionary<char, int>();
            col[i] = new Dictionary<char, int>();
            box[i] = new Dictionary<char, int>();
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                //当前没有字符 抬走 下一个
                if (board[i][j].Equals('.'))
                {
                    continue;
                }
                //计算宫的索引
                int k = i / 3 * 3 + j / 3;
                //当前元素对应的行集合,列集合,宫集合,都不重复
                if (!row[i].ContainsKey(board[i][j]) && !col[j].ContainsKey(board[i][j]) && !box[k].ContainsKey(board[i][j]))
                {
                    row[i].Add(board[i][j],i);
                    col[j].Add(board[i][j],j);
                    box[k].Add(board[i][j],k);
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
```