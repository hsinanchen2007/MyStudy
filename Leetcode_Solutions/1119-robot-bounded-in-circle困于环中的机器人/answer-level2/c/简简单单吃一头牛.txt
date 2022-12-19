```
struct Pos {
    int x;
    int y;
    int face;
};
enum ValidFace {
    NORTH,
    WEAST,    
    SOUTH,
    EAST
};
void HandleLeft(struct Pos *pos)
{
    pos->face++;
    if (pos->face == 4) {
        pos->face = 0;
    }
    //printf("trun left ->%d\n", pos->face);
}
void HandleRight(struct Pos *pos)
{
    pos->face--;
    if (pos->face == -1) {
        pos->face = 3;
    }
    //printf("true right -> %d\n", pos->face);
}
void HandlePos(struct Pos *pos)
{
    switch (pos->face) {
        case NORTH:
        pos->y++;
        break;
        case WEAST:
        pos->x--;
        break;
        case SOUTH:
        pos->y--;
        break;
        case EAST:
        pos->x++;
        break;
        default:
        break;
    }
    //printf("%d %d\n", pos->x, pos->y);
}
bool process(char *instructions, int len, int times, struct Pos *pos)
{
    while (times--) {
        for (int i = 0; i < len; i++) {
            if (instructions[i] == 'G') {
                HandlePos(pos);
            }
            if (instructions[i] == 'L') {
                HandleLeft(pos);
            }
            if (instructions[i] == 'R') {
                HandleRight(pos);
            }
        }
        if ((pos->x == 0) &&
            (pos->y == 0) &&
            (pos->face == NORTH)) {
            return true;
        }         
    }
   
    return false;
}
bool isRobotBounded(char *instructions)
{
    struct Pos pos = {0};
    int len = strlen(instructions);
    const int times = 10;

    pos.x = 0;
    pos.y = 0;
    pos.face = NORTH;
    return process(instructions, len, times, &pos);
}
```
