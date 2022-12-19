### 解题思路
一开始把很多方法混在一起写，发现变量会变的很乱。最后抽象出 方法 getNextCharFromFile 去解，就不会显得很乱。简单易懂。

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
        
        for(int i=0;i<n;i++)
        {
            char nextChar = getNextCharFromFile();
            
            if(nextChar==0)
            {
                return i;
            }
            else
            {
                buf[i] = nextChar; 
            }
        }
        
        
        return n;
  
    }
    
    public char getNextCharFromFile()
    {        
        if(readOffset == bufSize)
        {
            //buf is full
            //need new read
            
            bufSize = read4(fileBuf);
            readOffset = 0;
            
            if(bufSize==0)
            {
                return 0;
            }
            
        }
        
        return fileBuf[readOffset++];        
        
    }
    
    private char[] fileBuf = new char[4];
    private int readOffset = 0;
    private int bufSize = 0;
    
    
    
    
    
}
```