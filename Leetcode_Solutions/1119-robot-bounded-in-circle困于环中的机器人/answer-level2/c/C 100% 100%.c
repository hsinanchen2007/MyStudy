### 解题思路
走一遍才知道！


### 代码

```c
bool isRobotBounded(char *instructions)
{
    if (instructions == NULL) {
        return true;
    }
    int len = strlen(instructions);
    int x = 0;
    int y = 0;
    int step = 0;
    int flag = 0;
    for (int i = 0; i < len; i++) {

        if (flag == 0) {
            if (instructions[i] == 'L') {
                flag = 3;
            }
            if (instructions[i] == 'R') {
                flag = 1;
            }
            if (instructions[i] == 'G') {
                y++;
            }
        } else if (flag == 1) {
            if (instructions[i] == 'L') {
                flag = 0;
            }
            if (instructions[i] == 'R') {
                flag = 2;
            }
            if (instructions[i] == 'G') {
                x++;
            }

        } else if (flag == 2) {
            if (instructions[i] == 'L') {
                flag = 1;
            }
            if (instructions[i] == 'R') {
                flag = 3;
            }
            if (instructions[i] == 'G') {
                y--;
            }

        } else if (flag == 3) {
            if (instructions[i] == 'L') {
                flag = 2;
            }
            if (instructions[i] == 'R') {
                flag = 0;
            }
            if (instructions[i] == 'G') {
                x--;
            }
        }
        if (instructions[i] == 'G') {
            step++;
        }
    }
    if (step == 0) {
        return true;
    }
    if (flag != 0) {
        return true;
    }
    if (x == 0 && y == 0) {
        return true;
    }
    return false;
}
```