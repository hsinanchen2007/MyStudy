### 思路
将好橘子和坏橘子的位置和时间信息分别放入两个队列中，每次弹出一个坏橘子，检查上下左右是否有好橘子，如果有，则从好橘子中取出，将加入坏橘子的队伍中。往复直到坏橘子全部弹出，此时如果好橘子的队列中还有值，则返回-1（不能全部感染），否则返回时间。

注意，这里的循环结束条件是坏橘子全部弹出，因为坏橘子仅仅只有一分钟的感染好橘子，要么把周围好橘子变成坏橘子，要么没有橘子可感染。

### 算法
- 创建需要用到的数据结构存储行、列、被感染的时间信息
- 挑出好橘子和坏橘子
- 把坏橘子四个方向上存在的好橘子变坏，直到没有好橘子可带坏
- 判断并返回结果
```c#
    public struct Loc
    {
        public int Row { get; set; }
        public int Col { get; set; }
        public int Minute { get; set; }
        public Loc(int row, int col, int min)
        {
            Row = row;
            Col = col;
            Minute = min;
        }
    }
   class Rotting_Oranges
    {
        public int OrangesRotting(int[][] grid)
        {
            List<Loc> fresh = new List<Loc>();
            List<Loc> rotting = new List<Loc>();

            for (int row = 0; row < grid.Length; row++)
                for (int col = 0; col < grid[row].Length; col++)
                {
                    if (grid[row][col] == 1)
                        fresh.Add(new Loc(row, col, 0));
                    if (grid[row][col] == 2)
                        rotting.Add(new Loc(row, col, 0));
                }
            int time = 0;//感染全部橘子的最长时间
            while (rotting.Count != 0)//如果还有坏橘子就能继续感染
            {
                Loc loc = rotting[0];
                time = time > loc.Minute ? time : loc.Minute;
                int m = ++loc.Minute;
                rotting.Remove(rotting[0]);
                if (fresh.Remove(new Loc(loc.Row + 1, loc.Col, 0)))
                    rotting.Add(new Loc(loc.Row + 1, loc.Col, m));
                if (fresh.Remove(new Loc(loc.Row - 1, loc.Col, 0)))
                    rotting.Add(new Loc(loc.Row - 1, loc.Col, m));
                if (fresh.Remove(new Loc(loc.Row, loc.Col + 1, 0)))
                    rotting.Add(new Loc(loc.Row, loc.Col + 1, m));
                if (fresh.Remove(new Loc(loc.Row, loc.Col - 1, 0)))
                    rotting.Add(new Loc(loc.Row, loc.Col - 1, m));
            }
            if (fresh.Count != 0)
                return -1;
            return time;
        }
}
```

### 注意
使用结构体的原因是`List.Remove()`方法只能按值剔除（结构体是值类型）。

### 优化
主要的优化点还是在空间上（上面的注意还是在想把结构体换成数组队列，结果一直返回-1才发现的😂，一开始真的注意不到这点）

暂时没有什么优化思路了，希望能在评论区交流交流。