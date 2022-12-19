兄弟们，加油鸭
春招奥利给
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
    char[] pre = new char[4];
    int next =0;
    int size =0;
    public int read(char[] buf, int n) {
        int i=0;
        if(next<size){
            i = build(buf,n,i);
        }
        while(i<n){
            size = read4(pre);
            next =0;
            i = build(buf,n,i);
            if(size<4){
                return i;
            }
        }
        return i;
    }

    private int build(char[] buf,int n,int i){
        for(;next<size&&i<n;){
            buf[i++] = pre[next++];
        }
        return i;
    }

}
```
