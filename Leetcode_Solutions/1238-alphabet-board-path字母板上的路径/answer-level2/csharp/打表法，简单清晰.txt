注意Z的处理

```c#
public class Solution
{
    struct Pos
    {
        public int x;
        public int y;
        public Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    public string AlphabetBoardPath(string target)
    {
        Pos[] pos = new Pos[256];
        int x = 0, y = 0;
        for (char i = 'a'; i <= 'z'; ++i)
        {
            pos[i] = new Pos(x / 5, y % 5);
            x++;
            y++;
        }

        StringBuilder sb = new StringBuilder();
        Pos prev = new Pos(0, 0);
        bool Z = false;
        foreach (char c in target)
        {
            int disX = pos[c].x - prev.x;
            int disY = pos[c].y - prev.y;

            string UD;
            string LR;

            if (disY < 0)
                LR = new string('L', -disY);
            else
                LR = new string('R', disY);

            if (disX < 0)
                UD = new string('U', -disX);
            else
                UD = new string('D', disX);

            if (Z)
                sb.Append(UD + LR);
            else
                sb.Append(LR + UD);

            sb.Append('!');

            prev = pos[c];
            Z = (c == 'z');

        }

        return sb.ToString();
    }
}
```