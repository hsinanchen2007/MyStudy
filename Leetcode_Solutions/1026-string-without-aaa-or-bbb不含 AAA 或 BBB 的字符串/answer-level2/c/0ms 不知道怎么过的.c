![image.png](https://pic.leetcode-cn.com/7ba99d3a2336c1cf8fa31b3c445931bdf8687a11843fd2dd03753bb5e0641902-image.png)

```
char * strWithout3a3b(int A, int B){
    if ((A == 0 && B >= 3) || (B == 0 && A >= 3)){
        return NULL;
    }

    char* buf = NULL;
    char fillchar;
    int reserve;
    int preset;
    int i;
    int size = A + B;
    buf = (char*)malloc(sizeof(char)*(size + 1));

    if(A >= B) {
        memset(buf, 'a', size);
        fillchar = 'b';
        preset = A;
        reserve = B;
    } else {
        memset(buf, 'b', size);
        fillchar = 'a';
        preset = B;
        reserve = A;
    }

    if (preset > 2*reserve + 2) {//aabaabaa都不满足
        free(buf);
        return NULL;
    }
    buf[size] = '\0';

    if (size < 3) { //2:0  1:1
        if (reserve !=0) {
            buf[0] = fillchar;
        }
        return buf;
    }
    for (i = 2; i < size; i=i+3) {//尝试aabaabaa
        if (reserve <= 0) {
            free(buf);
            return NULL;
        }
        buf[i] = fillchar;
        reserve--;
    }

    for (i = 1; i < size; i=i+3) {//尝试abbabba
        if (reserve <= 0) {
            return buf;
        }
        buf[i] = fillchar;
        reserve--;
    }

    return buf;
}
```
