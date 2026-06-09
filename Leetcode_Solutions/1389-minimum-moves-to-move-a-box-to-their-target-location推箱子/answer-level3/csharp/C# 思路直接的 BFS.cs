暴力BFS感觉也不容易写对，细节比较多，改了好几次。

为了保证最小用了个链表来BFS。

```c
public class Solution
{
    struct S
    {
        public int bx;
        public int by;
        public int px;
        public int py;
        public S(int a, int b, int c, int d)
        {
            bx = a; by = b; px = c; py = d;
        }
    }
    
    public int MinPushBox(char[][] grid)
    {
        S first = new S(0, 0, 0, 0);
        int n = grid.Length;
        int m = grid[0].Length;
        int tx = 0, ty = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                switch(grid[i][j])
                {
                    case 'B':
                    	first.bx = i;
                    	first.by = j;
                    	break;
                    case 'S':
                    	first.px = i;
                    	first.py = j;
                    	break;
                    case 'T':
                    	tx = i;
                    	ty = j;
                    	break;
                    default:
                    	break;
                }
            }
        }
        var qs = new LinkedList<S>();
        qs.AddLast(first);
        
        int[,] dir = new int[4, 2] { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        int[,,,] min = new int[n, m, n, m];
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                for(int k = 0; k < n; ++k)
                {
                    for(int l = 0; l < m; ++l)
                    {
                        min[i, j, k, l] = -1;
                    }
                }
            }
        }
        
        min[first.bx, first.by, first.px, first.py] = 0;
        
        while(qs.Count != 0)
        {
            S cur = qs.First();
            qs.RemoveFirst();
            int cx = cur.bx, cy = cur.by, ccx = cur.px, ccy = cur.py;
            int curmin = min[cx, cy, ccx, ccy];
            if(cx == tx && cy == ty) return curmin;
            for(int i = 0; i < 4; ++i)
            {
                int tmpx = ccx + dir[i, 0];
                int tmpy = ccy + dir[i, 1];
                //细节：箱子和人不能重合
                if(tmpx == cx && tmpy == cy) continue;
                if(tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && min[cx, cy, tmpx, tmpy] != curmin && grid[tmpx][tmpy] != '#')
                {
                    min[cx, cy, tmpx, tmpy] = curmin;
                    qs.AddFirst(new S(cx, cy, tmpx, tmpy));
                }
            }
            if(Math.Abs(cx - ccx) + Math.Abs(cy - ccy) == 1)
            {
                //细节：推箱子的逻辑
                int tmpcx = cx;
                int tmpcy = cy;
                if(cx < ccx)
                {
                    tmpcx--;
                }
                else if(cx > ccx)
                {
                    tmpcx++;
                }
                
                if(cy < ccy)
                {
                    tmpcy--;
                }
                else if(cy > ccy)
                {
                    tmpcy++;
                }
                
                if(tmpcx >= 0 && tmpcx < n && tmpcy >= 0 && tmpcy < m && grid[tmpcx][tmpcy] != '#' && min[tmpcx, tmpcy, cx, cy] == -1)
                {
                    min[tmpcx, tmpcy, cx, cy] = min[cx, cy, ccx, ccy] + 1;
                    qs.AddLast(new S(tmpcx, tmpcy, cx, cy));
                } 
            }
        }
        
        return -1;
    }
}
```