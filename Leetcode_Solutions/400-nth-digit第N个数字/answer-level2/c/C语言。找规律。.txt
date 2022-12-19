```
/**
 * 1位数的有9个     1-9
 * 2位数的有90个   10-99
 * 3为数的有900个 100-999
 * 通过n不断减去前面的位数来判断n在哪个区间
 * 比如n为125 那么125 > 9 * 1, n变为116, 116 < 90 * 2, 
 * 所以n位于10-99这个区间, 该区间每个数为2位，所以(116 - 1) / 2 = 57, 57 + 10 = 67(从1开始算，所以需要减1)
 * 最后在67里面找(116 - 1) % 2位置上的数
 */

int findNthDigit(int n){
    int bit = 1, spacing = 9;

    while(n > (long)spacing * bit){
        n -= spacing * bit;
        spacing *= 10;
        bit++;
    }
    
    int num = (n - 1) / bit + spacing / 9;
    char buf[32];
    sprintf(buf, "%d", num);
    
    return buf[(n - 1) % bit] - '0';
}
```
