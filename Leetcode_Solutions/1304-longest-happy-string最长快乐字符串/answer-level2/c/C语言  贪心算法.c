比赛时没有做出来，被三个数找最大值弄晕了，赛后冷静考虑了一下才弄明白；
贪心策略： 每次都优先放最多数的那个字符，如果某个字符被连续放了2次，仍数量最多，则将此字符设置为used，去找另外2个字符中多的那个往里放；
每次获取到可以放的字符时，清掉used，如果找不到下一个字符，则结束。
执行结果：通过
显示详情 执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.1 MB, 在所有 C 提交中击败了100.00%的用户
```
int used;
char GetNext(int *a, int *b, int *c)
{
    int m = *a, n = *b, p = *c;
    if (used == 1) { /* 哪个用过了，不参与比较 */
        m = 0;
    }
    if (used == 2) {
        n = 0;
    }
    if (used == 3) {
        p = 0;
    }
    if ((m >= n) && (m >= p) && (m > 0)) {
        (*a)--;
        used = 0;
        return 'a';
    }
    if ((n >= m) && (n >= p) && (n > 0)) {
        (*b)--;
        used = 0;
        return 'b';
    }
    if ((p >= m) && (p >= n) && (p > 0)) {
        (*c)--;
        used = 0;
        return 'c';
    }
    return '0';
}
char * longestDiverseString(int a, int b, int c)
{
    used = 0;
    char *res = calloc(a + b + c + 1, sizeof(char));
    char t;
    int cnt = 0;
    while (true) {
        t = GetNext(&a, &b, &c);
        if (t != '0') {
            res[cnt++] = t; 
        } else {
            break;
        }
        if ((cnt >= 2) && (res[cnt - 2] == 'a') && (res[cnt - 1] == 'a')) {
            used = 1;
        }
        if ((cnt >= 2) && (res[cnt - 2] == 'b') && (res[cnt - 1] == 'b')) {
            used = 2;
        }
        if ((cnt >= 2) && (res[cnt - 2] == 'c') && (res[cnt - 1] == 'c')) {
            used = 3;
        }
    }
    return res;
}
```
