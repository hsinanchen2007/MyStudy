![image.png](https://pic.leetcode-cn.com/ebe021cc9e8d8783e5e834b096b0ba9ae5aded37be75210c5a95d89f7f6fffbf-image.png)

**按照题意每一轮合并最前面和最后面的数据，然后添加括号即可，用到了sprintf函数来输出每次的合并。每次迭代N/2个数据，直到N=0时输出。
注：
1.最大球队数4096
2.尝试用itoa函数转换数字到字符串失败，手写了4位数的转换**

```
char *Itr(int n,int len, char **r) {
    char **x = NULL;

    if (n/2 == 0) {
        return r[0];
    }

    x = (char **)malloc(sizeof(char  *) * n/2);
    for (int i = 0, j = n-1; i < n/2 && j >= n/2; i++, j--) {
        x[i] = (char *)malloc(sizeof(char) * (len*2 + 5));
        sprintf(x[i], "(%s,%s)", r[i], r[j]);
    }

    return Itr(n/2, len*2 + 5, x);
}

char * findContestMatch(int n){
    char **x = NULL;
    int turn = n;

    x = (char **)malloc(sizeof(char  *) * n);
    for (int i = 0; i < n; i++) {
        x[i] = (char *)malloc(sizeof(char) * 5);
        x[i][0] = (char)(i + 1 + '0');
        x[i][1] = '\0';
        
        if (i >= 9 && i < 99){
            x[i][0] = (char)((i + 1) / 10 + '0');
            x[i][1] = (char)((i + 1) % 10 + '0');
            x[i][2] = '\0';
        }

        if (i >= 99 && i < 999) {
            x[i][0] = (char)((i + 1) / 100 + '0');
            x[i][1] = (char)(((i + 1) / 10 % 10)+ '0');
            x[i][2] = (char)((i + 1) % 10 + '0');
            x[i][3] = '\0';
        }
        if (i >= 999) {
            x[i][0] = (char)((i + 1) / 1000 + '0');
            x[i][1] = (char)(((i + 1) / 100 % 10)+ '0');
            x[i][2] = (char)(((i + 1) % 100) / 10 + '0');
            x[i][3] = (char)((i + 1) % 10 + '0');
            x[i][4] = '\0';
        }
    }

    return Itr(n, 5, x);
}
```

