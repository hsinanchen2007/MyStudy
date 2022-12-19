### 解题思路
其实这道题就是用每次读4个字符实现一次性读n个字符，前面正常循环读取，到了最后一次读取要注意，read4的返回值是实际读取的

### 代码

```c
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int _read(char* buf, int n) {
    int count = 0;
    int times = 0;
    while(n - 4 > 0) {
        count += read4(buf + count);
        n -= 4;
        times++;
    }
    int last;
    last = read4(buf + count); // 最后剩下了n个字符没读，实际读取了last个，当n恰好等于4的时候，需要判断实际读取了几个
    
    return times * 4 + MIN(last, n);
}
```