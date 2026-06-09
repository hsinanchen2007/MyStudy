### 解题思路
使用1775（0110 1110 1111）举例
index: 11   10   9   8   7   6   5   4   3   2   1   0
value: 0    1    1   0   1   1   1   0   1   1   1   1
dp   : 3    6    5   4   8   7   6   5   4   3   2   1
reIdx: 11   8    8   8   4   4   4   4  -1  -1  -1  -1
基于以上我们取最大的dp[index] = dp[7] = 8即可；
基础转移公式为dp[i] = dp[i - 1] + 1; 
初始reIdx = -1；当遇到0时，更新reIdx = 0对应的index,即reIdx = 4; 如上面的第一个value = 0,对应的index = 4;由于是第一个0，所以dp[i] = dp[i - 1] + 1;
当reIdx != -1时，再遇到0时，更新dp[i] = i - reIdx;即如上dp[8] = 8 - reIdx = 8 - 4 = 4;
以上类推；
![123.PNG](https://pic.leetcode-cn.com/84483e79d0666b679169fa042cc360f9ea9d899d1bc58149ac1d638dba94157a-123.PNG)

### 代码

```c
#define MAXS 33
int reverseBits(int num) {
    int dp[MAXS];
    memset(dp, 0, sizeof(int) * MAXS);
    unsigned int tmp = num;
    unsigned int i = 0;
    int idx, max;
    idx = max = -1;
    do {
        if ((tmp >> i) & 0x01 == 1) {
            if (i == 0) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        } else {
            if (i == 0) {
                dp[i] = 1;
            } else {
                if (idx == -1) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    dp[i] = i - idx;
                }
            }
            idx = i;
        }
        if (dp[i] >= max) {
            max = dp[i];
        }
        i++;
    } while (i <= 31);
    return max;
}
```