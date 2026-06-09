buf是一个指针，每次读取不能覆盖原来的地方，需要偏移4，然后如果可读的内容比n小，要返回读取的值，反之返回n原先的值
```
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0, result = 0, tmp = n;
        while (tmp > 0)
        {
            result += read4(buf + (count++ * 4));
            tmp -= 4;
        }
        return result < n ? result : n;
    }
};
```