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
     private int tmpCnt = 0;
     private int tmpPtr = 0;
     private char[] tmp = new char[4];
    public int read(char[] buf, int n) {
        int total = 0;
        while(total < n) {
            if(tmpPtr == 0) {
                tmpCnt = read4(tmp);
            }
            if(tmpCnt == 0) break;
            while(total < n && tmpPtr < tmpCnt) {
                buf[total++] = tmp[tmpPtr++];
            }
            if(tmpPtr == tmpCnt) tmpPtr = 0;
            if(tmpCnt < 4) break;
        }
        return total;
    }
}
```
