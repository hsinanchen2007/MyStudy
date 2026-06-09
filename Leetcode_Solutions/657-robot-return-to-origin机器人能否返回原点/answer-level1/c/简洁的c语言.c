```
bool judgeCircle(char* moves) {
    if (!moves)
        return true;

    int x = 0, y = 0;
    int i = 0;
    while (moves[i])
    {
        switch (moves[i])
        {
        case 'R':   ++x;    break;
        case 'L':   --x;    break;
        case 'U':   ++y;    break;
        case 'D':   --y;    break;
        default:
            break;
        }
        ++i;
    }
    return x == 0 && x == y ? true : false;
}
```
