先统计xx/yy和yy/xx的数量，取其偶数/2，再看有没有剩下单的xy/yx,有的话就加上
![image.png](https://pic.leetcode-cn.com/c4c8bc0a375ea428a343a38ebd68a2551c939c62d375ceb7f1dd5d954a591018-image.png)

````
int minimumSwap(char * s1, char * s2){
    int len = strlen(s1);
    if (len != strlen(s2)) {
        return -1;
    }
    if (strcmp(s1, s2) == 0) {
        return 0;
    }
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int ex = 0;
    int ey = 0;
    for (int i = 0; i < len; i++) {
        s1[i] == 'x' ? x1++ : y1++;
        s2[i] == 'x' ? x2++ : y2++;
        s1[i] == s2[i] ? (s1[i] == 'x' ? ex++ : ey++) : 0;
    }
    if ((x1 + x2) % 2 || (y1 + y2) % 2) {
        return -1;
    }
    x1 -= ex;
    y1 -= ey;
    x2 -= ex;
    y2 -= ey;
    return  x1 / 2 + y1 / 2 + x1 % 2 + y1 % 2;
}
```
