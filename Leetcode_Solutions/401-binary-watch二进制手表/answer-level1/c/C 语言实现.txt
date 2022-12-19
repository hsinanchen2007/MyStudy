C 语言实现
遍历 60 分钟 LED 的个数，再遍历出 12 小时 LED 的个数，如果相加等于 num，就保存。
```C []
char ** readBinaryWatch(int num, int* returnSize) {
    char **res = NULL;
    *returnSize = 0;
    int table[12] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3};
    for (int minute = 0; minute < 60; ++minute) {
        int i = (minute & 0x55) + ((minute >> 1) & 0x55);
        i = (i & 0x33) + ((i >> 2) & 0x33);
        i = (i & 0x0f) + ((i >> 4) & 0x0f);
        for (int hour = 0; hour < 12; ++hour) {
            if (i + table[hour] == num) {
                res = res ? (char**)realloc(res, (1 + (*returnSize)) * sizeof(char*)) : (char**)malloc(sizeof(char*));
                res[*returnSize] =  (char*)malloc(6 * sizeof(char));
                sprintf(res[(*returnSize)++], "%d:%02d", hour, minute);
            }
        }
    }
    return res;
}
```