### 解题思路
循环读，读不到或者读满为止

### 代码

```java
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
        int i=0;
        for(;i<n;){
            char[] b = new char[4];
            int t = read4(b);
             for(int j=0;j<t;j++){
                 if(i<n){
                    buf[i]=b[j];
                    i++;
                    }
                    else
                    break;
                }
            if(t!=4){
                break;
            }
        }
        return i;
    }
}
```