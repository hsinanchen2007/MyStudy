```
private boolean isSuccess(boolean[] count)
{
    int[][] success =
    {
        { 1, 2, 3 },
        { 1, 4, 7 },
        { 1, 5, 9 },
        { 2, 5, 8 },
        { 3, 6, 9 },
        { 3, 5, 7 },
        { 4, 5, 6 },
        { 7, 8, 9 } 
    };
    for (int[] s : success)
    {
        if (count[s[0]] && count[s[1]] && count[s[2]])
        {
            return true;
        }
    }
    return false;
}

public boolean validTicTacToe(String[] board)
{
    int Xnum = 0, Onum = 0, index = 0;
    boolean[] Xcount = new boolean[10];
    boolean[] Ocount = new boolean[10];
    for (String s : board)
    {
        for (char c : s.toCharArray())
        {
            index++;
            if (c == 'X')
            {
                Xcount[index] = true;
                Xnum++;
            }
            else if (c == 'O')
            {
                Ocount[index] = true;
                Onum++;
            }
        }
    }
    if (Xnum == Onum && !isSuccess(Xcount) || Xnum == Onum + 1 && !isSuccess(Ocount))
    {
        return true;
    }
    return false;
}
```
