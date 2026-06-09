### 解题思路
此处撰写解题思路

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
        int index = 0;
        char[] tmp = new char[4];
        for (int i=0; i < n/4; i++) {      
            int realCount = read4(tmp);
            addTo(buf, index, tmp, realCount);
            index += realCount;
            if (realCount < 4) return index;
        }
        if (index < n) {
            // 此处返回的copyCount可能大于需要的长度
            int copyCount = Math.min(read4(tmp), n - index);
            addTo(buf, index, tmp, copyCount);
            index += copyCount;
        }
        return index;
    }

    private void addTo(char[] toBuf, int insertIndex, char[] fromBuf, int copyCount) {
        if (copyCount <= 0) return;
        for(int i=0 ; i<copyCount; i++) {
            toBuf[insertIndex + i] = fromBuf[i];
        }
    }

}
```