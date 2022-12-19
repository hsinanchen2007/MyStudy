首先每行的最大座位是2个四连坐，所以初始结果为n*2。然后遍历被订座位的二维数组，一行可以四连座的位置分为**左**、**中**、**右**，
计算每行的剩余可行的数量。
如果第一次遍历到该行，剩余四连座数量就是**2**，然后再去减**1**，并记录是少掉左中右哪**1**块或者哪**2**块四连座。
如果只剩**1**个座位的，判断下是否需要再减去一个四连座数量（也就是这一行没有四连座）。
如果当前四连座数量为**0**跳过循环。
```
public int MaxNumberOfFamilies(int n, int[][] reservedSeats) {
        int res = n * 2;
        Dictionary<int, int[]> dp1 = new Dictionary<int, int[]>();
        foreach (var item in reservedSeats)
        {
            var col = item[1];
            if (col == 1 || col == 10)
            {
                continue;
            }
            var line = item[0];
            if (!dp1.ContainsKey(line))
            {
                dp1.Add(line, new int[4] { 2, 1, 1, 1 });//开头为每行最大数量2，接下来为左中右是否还有连坐
            }
            else if (dp1[line][0] == 0)
            {
                continue;
            }

            if (col == 2 || col == 3)
            {
                dp1[line][1] = 0;
            }
            else if (col == 4 || col == 5)
            {
                dp1[line][1] = 0;
                dp1[line][2] = 0;
            }
            else if (col == 6 || col == 7)
            {
                dp1[line][2] = 0;
                dp1[line][3] = 0;
            }
            else if (col == 8 || col == 9)
            {
                dp1[line][3] = 0;
            }

            if (dp1[line][0] == 2)
            {
                dp1[line][0] = 1;
                res--;
            }
            else if (dp1[line][0] == 1)
            {
                if (((col == 2 || col == 3) && (dp1[line][2] == 0 && dp1[line][3] == 0))//如果是左占座位了并且中和右没有了
                    || ((col == 8 || col == 9) && (dp1[line][1] == 0 && dp1[line][2] == 0))//如果是右占座了并且左和中没有了
                    || ((col == 4 || col == 5) && (dp1[line][3] == 0))//如果是左、中占座了并且右没有了
                    || ((col == 6 || col == 7) && (dp1[line][1] == 0)))//如果是后、中占座了并且左没有了
                {
                    dp1[line][0] = 0;
                    res--;
                    continue;
                }
            }

        }
        return res;
    }
```
