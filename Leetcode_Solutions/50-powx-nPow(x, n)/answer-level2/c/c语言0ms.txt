
#define BIT_NUM  32
double myPow(double x, int n){
    int xx[BIT_NUM] = {0x1, 0x2, 0x4, 0x8, 
        0x10, 0x20, 0x40, 0x80, 
        0x100, 0x200, 0x400, 0x800,
        0x1000, 0x2000, 0x4000, 0x8000,
        0x10000, 0x20000, 0x40000, 0x80000,
        0x100000, 0x200000, 0x400000, 0x800000,
        0x1000000, 0x2000000, 0x4000000, 0x8000000,
        0x10000000, 0x20000000, 0x40000000, 0x80000000};
    int yy[BIT_NUM];
    double val[BIT_NUM];
    double ret;
    int i, y;
    int flag = 0;
    unsigned int  temp = n;
    int cnt = 0;
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    y = n;
    if (n < 0) {
        if (n == 0x80000000) {
            y = 0x7fffffff;
            flag = 1;
        } else {
            y = -n;
        }
        x = 1/x;
    }
    while (y > 0) {
        for (i = 1; i < BIT_NUM; i++) {
            if ((unsigned int)y < (unsigned int)xx[i]) {
                yy[cnt++] = i - 1;
                y = y - xx[i - 1];
                break;
            }
        }
    }
    val[0] = x;
    for (i = 1; i <= yy[0]; i++) {
        val[i] = val[i - 1] * val[i - 1];
    }
    ret = val[yy[0]];
    for (i = 1; i < cnt; i++) {
        ret = ret * val[yy[i]];
    }
    if (flag) {
        ret = ret * x;
    }
    return ret;
}