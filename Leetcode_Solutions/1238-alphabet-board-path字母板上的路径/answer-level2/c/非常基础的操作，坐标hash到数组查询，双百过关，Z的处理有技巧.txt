
```c
/*
abcde
fghij
klmno
pqrst
uvwxy
z
*/
char g_x[26] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0};
char g_y[26] = {0 ,0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5};
char * alphabetBoardPath(char * target){
    char *path = (char *)malloc(1000);
    char *c = target;
    char lx = 0;
    char ly = 0;
    int cur = 0;
    while (*c) {
        char x = g_x[*c - 'a'];
        char y = g_y[*c - 'a'];
        // z的位置特殊，尽量安排先往左走，和往上走，即可规避。
        if (y < ly) {
            for (int i = y; i < ly; i++) {
                path[cur++] = 'U';
            }
        }
        if (x < lx) {
            for (int i = x; i < lx; i++) {
                path[cur++] = 'L';
            }
        }
        if (y > ly) {
            for (int i = ly; i < y; i++) {
                path[cur++] = 'D';
            }
        }
        if (x > lx) {
            for (int i = lx; i < x; i++) {
                path[cur++] = 'R';
            }
        }

        path[cur++] = '!';
        lx = x;
        ly = y;
        c++;
    }
    path[cur] = '\0';
    return path;
}
```
![image.png](https://pic.leetcode-cn.com/d516749f10495307770973922c827bb02f41a054652454d85c38b1f4345023c2-image.png)
