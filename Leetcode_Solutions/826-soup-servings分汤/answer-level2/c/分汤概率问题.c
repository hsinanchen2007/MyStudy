### 解题思路
数学思路是概率论贝叶斯全概率公式，算法思路是动态规划(自底而上)算法
### 代码

```c
#inclue <math.h>
int M(int i)
{
    return (i > 0) ? i : 0;
}
double soupServings(int N){
    if (N >= 10000) {
        return 1.0;
    }
    N = (int)ceil((double)N / 25);
    int i = 0, j = 0, i1 = 0, j1 = 0;
    double p = 0;
    double** mem = (double**)malloc(sizeof(double*) * (N + 1));
    for (i = 0; i < N + 1; i++) {
        mem[i] = (double*)malloc(sizeof(double) * (N + 1));
        memset(mem[i], 0, sizeof(double) * (N + 1));
    }
    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < N + 1; j++) {
            p = 0;
            if (i <= 0 && j > 0) {
                p = 1;
            } else if (i <= 0 && j <= 0) {
                p = 0.5;
            } else if (i > 0 && j <= 0) {
                p = 0;
            } else {
                i1 = M(i - 4);
                j1 = j;
                p = p + mem[i1][j1];
                i1 = M(i - 3);
                j1 = M(j - 1);
                p = p + mem[i1][j1];
                i1 = M(i - 2);
                j1 = M(j - 2);
                p = p + mem[i1][j1];
                i1 = M(i - 1);
                j1 = M(j - 3);
                p = p + mem[i1][j1];
                p = p * 0.25;
            }
            mem[i][j] = p;
        }
    }
    return mem[N][N];
}

```