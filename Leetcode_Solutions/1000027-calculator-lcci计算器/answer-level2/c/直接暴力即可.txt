![image.png](https://pic.leetcode-cn.com/e10043f983736d1513ef94dff6700f9bbbbea3d343fd63352a94dc3fac0e70f6-image.png)

#define MAXLEN 20
#define MAXNUM 100000

int calculate(char* s)
{
    int data[MAXNUM] = {0};
    int num = 0;
    int lastNum = 1;
    char lastSyp = '+';
    int rel = 0;

    while (*s != '\0') {
        char src[MAXLEN] = {0};
        int len = 0;

        /*去掉空格*/
        while (*s != '\0' && *s == ' ') {
            s++;
        }
        while (*s != '\0' && *s <= '9' && *s >= '0') {
            src[len++] = *s++;
        }
        //printf("src=%s\n", src);
        /*去掉空格*/
        while (*s != '\0' && *s == ' ') {
            s++;
        }
        /*后面非乘除号*/
        if (*s == '\0' || *s == '+' || *s == '-') {
            int curNum = atoi(src);
            if (lastSyp == '*') {
                data[num++] = lastNum * curNum;
            } else if (lastSyp == '/') {
                data[num++] = lastNum / curNum;
            } else if (lastSyp == '-') {
                data[num++] = (-1) * curNum;
            } else {
                data[num++] = curNum;
            }             
        } else if (*s == '*' || *s == '/') {
            int curNum = atoi(src);
            if (lastSyp == '*') {
                lastNum *= curNum;
            } else if (lastSyp == '/') {
                lastNum /= curNum;
            } else if (lastSyp == '-') {
                lastNum = (-1) * curNum;
            } else {
                lastNum = curNum;
            }             
        }
        lastSyp = *s;
        //printf("lastSyp=%c\n", lastSyp);

        if (*s != '\0') {
            s++;
        }
    }

    for (int i = 0; i < num; i++) {
        rel += data[i];
    }

    return rel;
}
