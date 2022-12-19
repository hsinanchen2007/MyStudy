非常经典的题目，在CSAPP书中作者有类似的演示代码(rio_readlinen函数)，基本思路是利用缓冲区，既可以使得函数能被多次调用，也可加快读取速度。
这里的代码与CSAPP中的非常类似，只是没有将内部buff抽象成独立数据结构

```
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int cache_cnt = 0;
    char cache_buf[4];
    char * cache_pointer;
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while (cnt < n) {
            if (cache_cnt <= 0) {
                memset(cache_buf, 0, 4);
                cache_cnt = read4(cache_buf);
                cache_pointer = cache_buf;
                if (cache_cnt <= 0) {
                    break;
                }
            }
            int cpy_cnt = min(cache_cnt, n - cnt);
            memcpy(buf, cache_pointer, cpy_cnt);
            cache_pointer += cpy_cnt;
            cache_cnt -= cpy_cnt;
            cnt += cpy_cnt;
            buf += cpy_cnt;
        }
        return cnt;
    }
};
```
