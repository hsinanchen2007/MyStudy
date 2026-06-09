### 解题思路
此处撰写解题思路
asscii码表一共128个元素，所以用一个128的数组就可以统计到字符串中每个元素出现的次数；
然后再依次求出最大的次数，并且进行连续赋值，赋值之后把该索引次数清零，继续求次大值，以此类推。
### 代码

```c


char * frequencySort(char * s){
    int tempLen = strlen(s);
    int i = 0;
    int j = 0;
    char letter[128] = {0};
    int index[128] = {0};
    int max = 0;
    int maxIndex = 0;
    char *ret = malloc(sizeof(char) * (tempLen + 1));
    *(ret + tempLen) = '\0';
    for (i = 0; i < 128; i++) {
        letter[i] = i;
        printf("000 test code letter[%d] is %c\n",i,letter[i]);
    }

    for (i = 0; i < tempLen; i++) {
        index[s[i]] = index[s[i]] + 1;

    }
    int m = 0;
    int p = 0;
    for (i = 0; i < 128; i++) {
        max = 0;
        maxIndex = 0;
        for (j = 0; j < 128; j++) {
            if (index[j] > max) {
                max = index[j];
                maxIndex = j;
            }
        }
        for (m = 0; m < max; m++) {
            *(ret + p + m) = letter[maxIndex];
        }
        p = p + max;
        index[maxIndex] = 0;
    }
    return ret;
}
```