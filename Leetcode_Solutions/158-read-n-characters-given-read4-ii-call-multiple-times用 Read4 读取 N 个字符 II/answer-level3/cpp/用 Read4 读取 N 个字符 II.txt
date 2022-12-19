### 解题思路
递归或者循环
类比煮饭
### 代码

```cpp
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    //电饭锅，容量为4
    vector<char> m_lastBuff = vector<char>(4);
    int m_lastBuffSize = 0;
    int m_lastBuffStart = 0;

    int read(char *buf, int n) {
        if(n <= 0)
        {
            return 0;
        }
        // 每次只能煮最多4单位的米，因为电饭煲大小就这么小
        // 而且米不一定够
        // 超过4单位，则需要分批煮————递归/循环；
        if(n>4)
        {
            int got = read(buf, 4);
            // 没米了，别煮了
            if (got<4)
            {
                return got;
            }
            return got+read(buf+4,n-4);
        }

        // 剩饭够填饱肚子
        if(m_lastBuffSize>=n)
        {
            for(int i=0;i<n;++i)
            {
                buf[i]=m_lastBuff[i+m_lastBuffStart];
            }

            m_lastBuffSize -= n;  // 修改剩饭的量
            m_lastBuffStart += n; // 修改剩饭的起始位置；
            return n;
        }
        // 不够吃
        // 先把剩饭吃完，电饭锅空出来，再煮一点饭
        else
        {
            // 吃剩饭
            int idx=0;
            for(;idx<m_lastBuffSize;++idx)
            {
                buf[idx]=m_lastBuff[m_lastBuffStart+idx];
            }
            // 开始煮饭
            m_lastBuffSize=read4(&m_lastBuff[0]);
            m_lastBuffStart = 0;
            // 没米了，煮了个寂寞，洗洗睡吧
            if(m_lastBuffSize <= 0)
            {
                return idx;
            }
            

            // 还没吃饱，而且还有饭吃
            int j=0;
            while(idx<n && m_lastBuffSize>0)
            {
                buf[idx] = m_lastBuff[j];
                ++idx;
                ++j;
                --m_lastBuffSize;
            }

            // 剩饭放在电饭锅里
            m_lastBuffStart = j;
                

            return idx;
        }

    
    }
};

```