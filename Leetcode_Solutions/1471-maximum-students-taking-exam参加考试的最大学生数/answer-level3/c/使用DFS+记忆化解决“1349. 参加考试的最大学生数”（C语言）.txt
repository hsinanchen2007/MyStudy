### 解题思路
经典DFS题型，类似八皇后问题，重点在于使用bit映射的memo进行加速，这里给出C语言的解法。

1.建立memo[i][j][p]用于记录在位置[i,j],前一级相关位置pattern为p的记忆表
![image.png](https://pic.leetcode-cn.com/889a5fa6eb4de78fe99a8d926f3a5eabff0e2ce7a015d72f6f68b2f7ece0af49-image.png)

2.建立flag用于记录访问情况，坏位置设置为2，占用为1，空为0

3.建立helper返回当前flag情况下，访问位置x，y，后面能够坐的最多的学生

4.建立辅助函数check用于检查当前位置是否合理，建立辅助函数用于获得当前pattern

5.开始dfs遍历，注意要遍历当前位置坐人和不坐人两种情况

![image.png](https://pic.leetcode-cn.com/2eb3f6a7aa7d98c9f9addeea804d1b9607943c02e4395d958a53a419f1f3c025-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MAX_LEN 8


int flag[MAX_LEN][MAX_LEN];
int row, col;

//后面的个数取决于当前进入时前面的pattern
// |      p p p p p |
// |p p p p x       |
int memo[MAX_LEN][MAX_LEN][512];

bool check(char **seats, int y, int x) {
/*
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d  ", flag[i][j]);
        }
        printf("\n");
    }
*/
    if( flag[y][x] == 2 || 
        (x > 0 && flag[y][x - 1] == 1) ||
        (x > 0 && y > 0 && flag[y - 1][x - 1] == 1) ||
        (x < col - 1 && y > 0 && flag[y - 1][x + 1] == 1)
        ) {
        //printf("[%d, %d], false\n", y, x);
        return false;
    } else {
        //printf("[%d, %d], true\n", y, x);
        return true;
    }
}

int get_pattern(char **seats, int y, int x) {
    int pattern = 0;
    for(int i = 0; i < x; i++) {
        if(flag[y][i] == 1) {
            pattern |= 1 << i;
        }
    }

    if(y == 0) {
        goto DONE;
    }

    for(int i = x; i < col; i++) {
        if(flag[y - 1][i] == 1) {
            pattern |= 1 << i;
        }
    }
    
    if(x > 0 && flag[y - 1][x - 1] == 1) {
        pattern |= 1 << col;
    }

DONE:
/*
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d  ", flag[i][j]);
        }
        printf("\n");
    }
*/
    //printf("pattern[%d, %d] = %d\n", y, x, pattern);

    return pattern;
}

int helper(char **seats, int y, int x) {
    if(y == row - 1 && x == col - 1) {
        int ret = check(seats, y, x) == true? 1 : 0;
        //printf("----max = %d\n", max);
        return ret;
    }

    //加速
    int p = get_pattern(seats, y, x);
    if(memo[y][x][p] != 0) {
        //printf("[%d, %d](%d)\n", y, x, memo[y][x][p] - 1);
        return memo[y][x][p] - 1;
    }

    int ret = 0;
    int ny = x + 1 == col? y + 1 : y;
    int nx = x + 1 == col? 0 : x + 1;

    if(check(seats, y, x) == true) {
        //占用
        flag[y][x] = 1;
        ret = helper(seats, ny, nx) + 1;
        flag[y][x] = 0;
    }

    //不占用
    ret = MMAX(ret, helper(seats, ny, nx));

    memo[y][x][p] = ret + 1;
    
    return ret;
}

//【算法思路】DFS。8皇后类型问题。
int maxStudents(char** seats, int seatsSize, int* seatsColSize){
    row = seatsSize;
    col = seatsColSize[0];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            flag[i][j] = seats[i][j] == '#'? 2 : 0;

            for(int k = 0; k < 512; k++) {
                memo[i][j][k] = 0;
            }
        }
    }

    int ret = helper(seats, 0, 0);

    return ret;
}
```