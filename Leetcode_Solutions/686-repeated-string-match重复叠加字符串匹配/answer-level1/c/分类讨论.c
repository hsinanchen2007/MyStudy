### 解题思路
重点在于确定A重复的遍数。
两种情况：
1. n >= m,少则一个A，多则两个A即可。返回值只能取 1，2，-1
2. n < m: 什么样的情况B才可能是A重复多遍的字串？ 首先，A的长度*重复次数>=B的长度（此处可获得最小的重复次数为m/n+1或者m/n，+1与否取决于是否整除）；其次，当A无限重复时候，比较长度达到 n+m-1，长度为m的字符串组合已经全部出现过了，再比都是重复字符组合。所以只需要A的重复字符串长度大于 n+m-1即可。 得到两个判断条件:  1. n*mintime>=m 2. n*maxtime >= n+m-1
3. 再mintime 和 maxtime 之间延申字符串并比较是否B已经是子串了。若延伸了maxtime次依然不是子串，则返回-1；

### 代码

```c
int repeatedStringMatch(char * A, char * B){
    int n = strlen(A);
    int m = strlen(B);
    //int copytime = 0;
    // A比B长或相等，copytime = 1 or 2
    if (n >= m) {
        if (strstr(A,B)) {
            return 1;
        }

        char * T[n * 2 + 1];
        strcpy(T,A);

        strcat(T,A) ;  //--------把A复制一遍,这里有问题
        if (strstr(T,B)) {
            return 2;
        }
        return -1;
    }
    // A比B短，至少A要复制到比B长，至多长于 m+n-1 即可
    int mintime, maxtime;
    if (n < m) {
        mintime = m / n;
        if (mintime * n < m) {
            mintime++;
        }
        maxtime = 1 + (m - 1) / n;
        if (maxtime * n < (n + m - 1)) {
            maxtime++;
        }
    }    

    for (int i = mintime; i <= maxtime; i++) {
        //copytime ++ ;

        char * T [i*n+1];              //申请一个临时空字符串，T
        T[0] = '\0';

        for (int j = 0; j < i; j++) {
            strcat(T,A);
        }

        if (strstr(T,B)) {
            return i;
        }
    }
    return -1;
}
```