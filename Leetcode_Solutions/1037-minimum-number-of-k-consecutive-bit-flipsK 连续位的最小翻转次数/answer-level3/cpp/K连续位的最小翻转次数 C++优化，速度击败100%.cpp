逻辑思路：

    一句话：A[i]上是否翻转只跟前面K-1个翻转状态有关。 详见官方题解，或者其他人的题解。

只讲优化：

    1，flip为前面K-1个翻转态之和，当前数组是否翻转取决于 (flip+A[i])是否为偶数。用 v & 0x1来判断即可。
    2，每次循环，flip需要更新，就是计算A[i-K+1]到A[i-1]之和，可以优化为：减去A[i-K]翻转态，然后加上A[i]翻转态
    3，若A[i]没翻转，flip就不需要++；
    4，用一个A.size()+K大小的数组标记翻转，加K可以保证i=0时，可以以同样的逻辑读取A[i-K]的翻转态。减少每次循环中的一次判断。而计算A[0]时，显然前面没有翻转过，所以初始化数组为0即可。

多K个字节，减少一次判断，从时间结果击败100%来看，显然很划算。

```cpp
class MinKBitFlips : public  MyDebug {
// class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // 声明一个大小为size的数组F，记录每个数组对应的奇偶性。初始化为0，均没有反转。（奇偶性原因参考其他题解）
        // 声明一个flip，计算当前A[i]是否需要反转， flip只跟前面K—1个数值的反转状态有关。
        // 计算A[i]时，flip = F[i-K+1] + ... + F[i-1], 实际只需 每次i++之后，flip需要减去F[i-K]，然后加上F[i]
        // 技巧： 我们声明flips代替数组F，实际多加K字节，flips[K+i] 对应 A[i]，前面多K个字节，用于防止数组访问越界
        // 所以flips[K+i]就是上面我们所说的F[i], flips[i]就是F[i-K]。为什么这么做？ 减少循环中的判断，提升性能哟。
        int size = A.size(), flip = 0, count = 0, i;
        vector<char> flips(K + size, 0);
        if (K > size) { return -1; }
        // 前面size-K+1个数组，每次先更新flip状态，先减去F[i-K]，如果翻转，当前F[i] = 1，flip += F[i]，返回结果count++。
        for (i = 0; i < size - K + 1; i++) {
            flip -= flips[i];
            if (!((A[i] + flip) & 0x1)) { flips[i+K] = 1; flip++; count++; }
        }
        // 因为需要同时翻转K个，后面K-1个数，没法翻转了；所以只要判断是否还有0即可。
        for (; i < size; i++) {
            flip -= flips[i];
            if (!((A[i] + flip) & 0x1)) { return -1; }
        }
        return count;
    }
};
```

测试代码：
```cpp

int MinKBitFlips_Tester() {
    int K = 3, ret;
    vector<vector<int>> AA{
            /*{0,0,},
            {0,0,0,},
            {1,1,1,},
            {1,1,1,1},
            {1,1,1,0},*/
            {0,1,1,0},
            {0,1,1,1},
            {1,0,0,0},
            {1,0,0,0,1},
            {0,1,1,0,0},
    };
    MinKBitFlips s;
    for (auto A: AA) {
        s.PrintVector(A,"input");
        cout << "K:" << K << endl;
        ret = s.minKBitFlips(A, K);
        cout << "result: " << ret << endl;
    }
}
```

