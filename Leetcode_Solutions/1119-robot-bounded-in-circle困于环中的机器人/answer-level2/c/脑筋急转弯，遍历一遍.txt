### 解题思路
此处撰写解题思路
脑筋急转弯，遍历一遍
如果，最后走不出，则给出的序列是一个循环节
2种情况:
1、本身刚好是个循环节，遍历一遍 最后的位置在原点
2、本身是循环节的一部分，则判断遍历一遍后的位置不在原点，则方向一定不与原点相同，相同就跑远了

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum dir { UP, DOWN, LEFT, RIGHT };

struct node {
    int x;
    int y;
    enum dir dir;
};

bool isRobotBounded(char *instructions)
{
    int loop;
    struct node pre;
    struct node cur;
    pre.x = 0;
    pre.y = 0;
    pre.dir = UP;

    if (!instructions || strlen(instructions) == 0)
        return true;

    for (loop = 0; loop < strlen(instructions); loop++) {
        cur = pre;
        switch (*(instructions + loop)) {
            case 'G':
                if (pre.dir == UP)
                    cur.y = pre.y + 1;
                else if (pre.dir == DOWN)
                    cur.y = pre.y - 1;
                else if (pre.dir == LEFT)
                    cur.x = pre.x + 1;
                else
                    cur.x = pre.x - 1;
                break;
            case 'L':
                if (pre.dir == UP)
                    cur.dir = LEFT;
                else if (pre.dir == DOWN)
                    cur.dir = RIGHT;
                else if (pre.dir == LEFT)
                    cur.dir = DOWN;
                else
                    cur.dir = UP;

                break;
            case 'R':
                if (pre.dir == UP)
                    cur.dir = RIGHT;
                else if (pre.dir == DOWN)
                    cur.dir = LEFT;
                else if (pre.dir == LEFT)
                    cur.dir = UP;
                else
                    cur.dir = DOWN;
                break;
            default:
                printf("error input\n");
                break;
        }
        pre = cur;
    }
    //printf("%d %d %d UP %d\n", cur.x, cur.y, cur.dir, UP);
    if (cur.x == 0 && cur.y == 0)
        return true;
    if (cur.dir != UP)
        return true;
    return false;
}
```