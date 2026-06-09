1、当不同的个数达到偶数的时候，才能够交换成功。否则无法交换成功；
2、当x或者y不同的个数为奇数时，计算规则是`(不同的个数/2)+1`；当x、y为不同的个数为偶数时，计算规则是`不同的个数/2`

```C
int minimumSwap(char * s1, char * s2){
    // 统计个数
    unsigned int xSum = 0;
    unsigned int ySum = 0;
    unsigned int loop;
    for (loop = 0; s1[loop] != '\0' && s2[loop] != '\0'; loop++) {
        if (s1[loop] != s2[loop]) {
            if (s1[loop] == 'x') {
                xSum++;
            } else if(s1[loop] == 'y') {
                ySum++;
            }
        }
    }
    
    if ((xSum + ySum) % 2 || s1[loop] != '\0' || s2[loop] != '\0') {
        return -1;
    }
    
    // 计算规则
    return (xSum % 2) ? ((xSum + ySum) / 2 + 1) : ((xSum + ySum) / 2);
}
```
