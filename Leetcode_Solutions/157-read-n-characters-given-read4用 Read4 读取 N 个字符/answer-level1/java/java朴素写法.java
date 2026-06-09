```
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf);
 */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        int index = 0;
        int sum = 0;
        if(n == 0) return 0;
        while(sum < n) {
            char[] tmp = new char[4];
            int size = read4(tmp);
            if(size == 0) break;
            // 处理不是4的整数倍时，最后要读多少个字符
            if(sum + size > n) {
                size = n - sum;
            }
            for(int i = 0; i < size; i++) {
                buf[index++] = tmp[i];
            }
            sum += size;
        }
        return index;
    }
}
```
