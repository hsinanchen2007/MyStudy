按照题目要求
如果start都是从0开始，每一个只能与上一个数有一个bit不同，然后我想到的规律是:
n == 0:[0,1]
n == 1:[00,01],[11,10]
n == 2:[000,001,011,010],[110,111,101,100]
依次类推，每提升一阶，就将上一阶得到的数组延长一倍，延长部分镜像复制前面的内容
同时在延长部分的最高位位翻转掉即可

start不为0的发现依旧可以这么玩，相当于在start为0的结果数组上统一异或上start的值
```
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> vi(1 << n); // 预先将vector的size调成最终长度
        vi[0] = start;
        for (int i = 1; i <= n; i++) {
            const int size = 1 << i;
            const int mask = 1 << (i - 1);
            for (int i = 0; i < mask; i++) {
                // 本次延长出来的部分，延长部分镜像复制前面的内容，同时在延长部分的最高位位翻转
                vi[size - 1 - i] = vi[i] ^ mask;
            }
        }

        return std::move(vi);
    }
};
```
