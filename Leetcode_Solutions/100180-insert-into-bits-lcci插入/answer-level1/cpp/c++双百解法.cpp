```
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        unsigned long int allones = 0xffffffff;
        int left = allones<<(j+1);
        int right = (1<<i)-1;
        int mask = left|right;
        int n_clear = N&mask;
        int put_m = M<<i;
        return put_m|n_clear;

    }
};
```
1.先清零n的i和j位，用掩码完成
2.再对m进行移位
3.合并处理好的m和n
