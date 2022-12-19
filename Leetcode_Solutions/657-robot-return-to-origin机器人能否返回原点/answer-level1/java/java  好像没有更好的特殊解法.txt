看作坐标轴
```
public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        for (char c : moves.toCharArray()) {
            if ('R' == c) x++;
            else if ('L' == c) x--;
            else if ('U' == c) y++;
            else y--;
        }
        return x == 0 && y == 0;
    }
```
