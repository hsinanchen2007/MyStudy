看了二楼C++那位的题解，自己拿Java写了一下，果然比我一个一个尝试简单多了，而且也更好理解。
首先判断能不能走到终点，走不到就直接返回false，然后把那些位置点在终点之前的障碍物作为“终点”，看能不能碰到，碰到就返回false。否则最后返回true。
```

    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int us=0,rs=0;
        char[] cmd =command.toCharArray();
        for (char c:cmd)
            if(c=='U')
                us++;
        rs=command.length()-us;
        int xstep = x/rs;
        int ystep = y/us;
        int min = xstep<ystep? xstep:ystep;
        int xpos = min*rs;
        int ypos = min*us;
        boolean reach = xpos == x && ypos == y;
        for (char c:cmd){
            if(c=='U') ypos++;
            else xpos++;
            if(xpos==x && ypos == y) {
                reach = true;
                break;
            }
        }
        if(!reach) return false;
        for (int[] obst: obstacles){
            if((obst[0]>=x && obst[1]>y) || (obst[0]>x && obst[1]>=y))
                continue;
            xstep = obst[0]/rs;
            ystep = obst[1]/us;
            min = xstep<ystep? xstep:ystep;
            xpos = min*rs;
            ypos = min*us;
            if(xpos==obst[0] && ypos==obst[1])
                return false;
            for (char c:cmd){
                if(c=='U') ypos++;
                else xpos++;
                if(xpos==obst[0] && ypos==obst[1])
                    return false;
            }
        }
        return true;
    }

```
