### 解题思路
每次读4个char直到最后，小心处理边界条件即可

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
        
        int charNums = 0;
        
        //buf = new char[n];
        
        here:
        for(int i=0;i<n;i+=4)
        {
            //i is start point
            
            char[] eachBuf = new char[4];
            int m = read4(eachBuf);
            
            if(m==0)
            {
                break;
            }
            
            for(int j = 0; j<m; j++, charNums++)
            {
                buf[i+j] = eachBuf[j];
                
                
                if(i+j == n)
                {
                    break here;
                }
            }            
        }
        
        return charNums;
        
        
    }
}
```