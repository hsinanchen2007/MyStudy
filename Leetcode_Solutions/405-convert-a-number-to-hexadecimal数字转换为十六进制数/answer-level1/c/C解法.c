```
char * toHex(int num){
    int index = 0;
    char *ret = calloc(9, sizeof(char));
    ret[0] = '0';

    unsigned int ui = (unsigned int) num;   // C使用补码存储，故直接转换为uint32_t处理即可
    for (int i = 0; i < 8; ++i) {
        unsigned int temp = (ui & 0xF0000000) >> 28;
        if ((!index && temp) || index) {
            ret[index++] = ((temp >= 10) ? ('a' + temp - 10) : ('0' + temp));
        }
        ui = ui << 4;
    };

    return ret;
}
```
