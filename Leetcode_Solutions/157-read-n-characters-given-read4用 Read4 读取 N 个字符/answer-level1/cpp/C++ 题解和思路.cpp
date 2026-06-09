就是循环读文件，注意点在注释中
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
        if (buf == nullptr || n <= 0)
            return 0;

        int total = 0, current = 0;
        // 循环读文件，直到文件全部读完或者超过需要的字符
        do {
            current = read4(buf + total);
            total += current;
        } while (current == 4 && total < n);

        // 如果有读入的字符超过需要的字符数，例如：“abcd”，但是只要读3个字符
        // 那么需要清除多余的字符
        if (total > n) {
            buf[n] = 0;
            total = n;
        }
        
        return total;
    }
};
```
