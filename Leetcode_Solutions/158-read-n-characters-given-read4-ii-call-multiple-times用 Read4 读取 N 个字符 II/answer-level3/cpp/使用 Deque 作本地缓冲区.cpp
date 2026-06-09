### 解题思路

使用双端队列作为本地缓冲区，保存上次读剩下的字符。

### 代码

```cpp
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    deque<char> localBuf;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count;
        int lastSize = localBuf.size();
        
        for(count=0; count < lastSize; count++) {
            buf[count] = localBuf.front();
            localBuf.pop_front();
            if(count == n - 1)
                return n;
        }
        while(count < n) {
            int num = read4(buf + count);
            count += num;
            if(num < 4)
                break;
        }
        int left = n;
        while(left < count) {
            localBuf.push_back(buf[left++]);
        }

        return min(count, n);   
    }
};
```