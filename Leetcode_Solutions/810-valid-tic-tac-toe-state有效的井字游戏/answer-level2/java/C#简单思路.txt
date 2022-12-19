统计X和O的数量，顺便统计谁赢得了这盘游戏，根据X和O的数量以及是否有人取胜，做出相应判断即可。
```java []
public boolean validTicTacToe(String[] board) {
        int XCount = 0;
            int OCount = 0;
            boolean[] b = new boolean[2];//01 X  23 O
            int[] re = new int[6];
            for(int i=0;i<3;i++)
            {
                int x = 0; int o = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (board[i].charAt(j) == 'X') 
                    { 
                        x++;
                        re[j]++;
                    }
                    else if (board[i].charAt(j) == 'O') 
                    { 
                        o++;
                        re[j + 3]++;
                    }
                }
                XCount += x;
                OCount += o;
                if (x == 3) b[0] = true;
                else if (o == 3) b[1] = true;
            }
            for (int i = 0; i < re.length;i++ )
            {
                if(re[i]==3)
                {
                    if (i < 3) b[0] = true;
                    else b[1] = true;
                }
            }
            char cen=board[1].charAt(1);
            if ((cen == board[0].charAt(0) && cen == board[2].charAt(2)) || cen == board[0].charAt(2) && cen == board[2].charAt(0))
            {
                if (cen == 'X') b[0] = true;
                else if(cen=='O') b[1] = true;
            }
            if (XCount - OCount > 1||OCount>XCount) return false;
            if (b[0] && b[1]) return false;
            if ((b[0] && XCount == OCount) || (b[1] && XCount > OCount)) return false;
            return true;
    }
```
```C# []
public bool ValidTicTacToe(string[] board) {
            int XCount = 0;
            int OCount = 0;
            bool[] b = new bool[2];//01 X  23 O
            int[] re = new int[6];
            for(int i=0;i<3;i++)
            {
                int x = 0; int o = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == 'X') 
                    { 
                        x++;
                        re[j]++;
                    }
                    else if (board[i][j] == 'O') 
                    { 
                        o++;
                        re[j + 3]++;
                    }
                }
                XCount += x;
                OCount += o;
                if (x == 3) b[0] = true;
                else if (o == 3) b[1] = true;
            }
            for (int i = 0; i < re.Length;i++ )
            {
                if(re[i]==3)
                {
                    if (i < 3) b[0] = true;
                    else b[1] = true;
                }
            }
            char cen=board[1][1];
            if ((cen == board[0][0] && cen == board[2][2]) || cen == board[0][2] && cen == board[2][0])
            {
                //对角线取胜
                if (cen == 'X') b[0] = true;
                else if(cen=='O') b[1] = true;
            }
            if (XCount - OCount > 1||OCount>XCount) return false;
            //不能两人同时取胜
            if (b[0] && b[1]) return false;
            //取胜条件判断
            if ((b[0] && XCount == OCount) || (b[1] && XCount > OCount)) return false;
            return true;
    }
```

