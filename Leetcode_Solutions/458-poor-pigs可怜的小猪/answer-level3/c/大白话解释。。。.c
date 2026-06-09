### 解题思路
就是说，一个桶可以记录以下信息，他是被第1头猪第几次喝的，第2头猪第几次喝的，一直到第n头猪第几次喝的，如果最少的猪，肯定u最多的桶，每个桶的信息也各不相同，要不然就不是最少的猪，   然后我们通过实验可以知道每头猪的死亡时间，然后调查每个桶，拘留嫌疑桶，然后在此基础上继续排查，直到某个嫌疑人的时间线和所有猪的死亡时间全对上了，他就是凶手。

### 代码

```cpp
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
int sta=minutesToTest/minutesToDie+1;
        return ceil(log(buckets)/log(sta));

    }
};
```