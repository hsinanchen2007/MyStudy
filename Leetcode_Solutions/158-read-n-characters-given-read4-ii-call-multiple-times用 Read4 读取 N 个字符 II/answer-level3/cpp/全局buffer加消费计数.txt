### 解题思路
因为要用多次read4来完成一次read，那么可能会出现read要求的size不是4的整数倍，那么在buf结尾就可能出现多余数据，而多余数据将是下一次read的起始数据，不能丢弃，所以我们需要一个类成员buf4来存储当前read4返回的数据，其生命周期跟随整个类，而不是read方法；另外再使用两个类变量readCnt和readConsumed来记录当前read4返回的数据量和已经消耗掉的数据量
1）buf4 -- 保存最近一次read4返回的数据
2）readCnt -- 保存最近一次read4返回的数据大小
3）readConsumed -- 保存最近一次read4返回数据中，已经被read消费掉的大小

### 代码

```cpp
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char * buf4 = new char[4];
    int readCnt = 0;
    int readConsumed = 0;
    int read(char *buf, int n) {
        int total = 0;
        while(true) {
            if (readConsumed < readCnt) {
                if ((total + (readCnt - readConsumed)) >= n) {
                    memcpy(buf+total, buf4 + readConsumed, n - total);
                    readConsumed += (n - total);
                    total = n;
                    break;
                } else {
                    memcpy(buf+total, buf4 + readConsumed, readCnt - readConsumed);
                    total += (readCnt - readConsumed);
                    readConsumed = readCnt;
                }
            } else {
                readConsumed = 0;
                readCnt = read4(buf4);
                //printf("readCnt = %d\n", readCnt);
                if (readCnt <= 0)
                    break;
            }
        }
        return total;
    }
};
```