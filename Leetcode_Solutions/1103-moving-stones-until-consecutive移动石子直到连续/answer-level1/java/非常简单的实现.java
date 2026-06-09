直接上代码吧：
```
    public int[] numMovesStones(int a, int b, int c) {
        int[] step = new int[2];
        int x = Math.min(a, Math.min(b, c));
        int z = Math.max(a, Math.max(b, c));
        int y = a + b + c - x - z;
        if(y - x > 2 && z - y > 2) {
            step[0] = 2;
        }else if(x + 1 == y && y + 1 == z) {
            step[0] = 0;
        }else{
            step[0] = 1;
        }
        step[1] = z - x - 2;
        return step;
    }
```
