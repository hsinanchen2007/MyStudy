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
    char local_buf[4] = {0};
    int l = 0;
    int r = 0;
    int read(char *buf, int n) {
        int s = 0;
        while (l < r && n > 0) {
            buf[s++] = local_buf[l++];
            --n;
        }
        if (n == 0)
            return s;
        int k = n / 4;
        for (int i = 0; i < k; ++i) {
            l = 0;
            r = read4(local_buf);
            while (l < r && n > 0) {
                buf[s++] = local_buf[l++];
                --n;
            }
            if (r < 4)
                return s;
        }
        if (n == 0)
            return s;
        l = 0;
        r = read4(local_buf);
        while (l < r && n > 0) {
            buf[s++] = local_buf[l++];
            --n;
        }
        return s;
    }
};```
