### 解题思路
此题采用暴力搜索，找到符合条件的所有组合。重点考察点是位操作，hour和minute都是检索二进制1的个数然后求和。注意二维指针申请时要分段malloc

### 代码

```c
int getBitNum(int d) {
    int i = 0;

    while (d != 0) {
        if (d % 2 == 1) {
            i++;
        } 

        d = d >> 1;
    }

    return i;
}

char ** readBinaryWatch(int num, int* returnSize) {
    int hour, min;
    int k = 0;
    int m;
    char **s;

    *returnSize = 0;
    
    for (hour = 0; hour < 12; hour++) {
        for (min = 0; min < 60; min++) {
            k = getBitNum(min) + getBitNum(hour);

            if (k == num) {
                (*returnSize)++;
            }
        }
    }

    s = (char **)malloc(sizeof(char*) * (*returnSize));

    for (m = 0; m < *returnSize; m++) {
        s[m] = (char *)malloc(sizeof(char) * 6);
    }

    m = 0;
    for (hour = 0; hour < 12; hour++) {        
        for (min = 0; min < 60; min++) {
            k = getBitNum(min) + getBitNum(hour);

            if (k == num) {
                sprintf(s[m++], "%d:%02d",hour,min);
            }
        }
    }

    return s;
}
```