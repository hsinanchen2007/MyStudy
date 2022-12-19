 public int NumRookCaptures(char[][] board)
    {
        int wide = 0;
        int hight = 0;
        for (int i = 0; i < board.Length; i++)
            for (int j = 0; j < board[i].Length; j++)
            {
                if (board[i][j] == 'R')
                {
                    wide = j;
                    hight = i;
                }
            }
        north = hight - 1;
        south = hight + 1;
        int num = 0;
        while (north != -1 || south < board.Length)
        {
            num += Lift(board, wide, true);
        }
        north = wide - 1;
        south = wide + 1;
        while (north != -1 || south < board[hight].Length)
        {
            num += Lift(board, hight, false);
        }
        return num;
    }
    private int Lift(char[][] board, int wide, bool isLift)
    {
        int num = 0;
        if (north != -1)
        {
            bool isAdd = isLift ? board[north][wide] == 'p' : board[wide][north] == 'p';
            bool isClose = isLift ? board[north][wide] == 'B' : board[wide][north] == 'B';
            num += isAdd ? 1 : 0;
            north = isAdd || isClose ? -1 : north - 1;
        }
        int length = isLift ? board.Length : board[0].Length;
        if (south < length)
        {
            bool isAdd = isLift ? board[south][wide] == 'p' : board[wide][south] == 'p';
            bool isClose = isLift ? board[south][wide] == 'B' : board[wide][south] == 'B';
            num += isAdd ? 1 : 0;
            south = isAdd || isClose ? length : south + 1;
        }
        return num;
    }
