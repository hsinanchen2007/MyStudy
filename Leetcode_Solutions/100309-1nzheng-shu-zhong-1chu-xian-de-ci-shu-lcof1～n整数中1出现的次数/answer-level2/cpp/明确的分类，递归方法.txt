对数字`23456`，可以划分成两类问题考虑
1. 考虑最高位为1出现的个数
2. 考虑非最高位为1出现的个数
    - 考虑 `> 3456` 中非最高位为1出现的个数
    - 考虑 `[1, 3456]` 中非最高位为1出现的个数

对第一类问题
1. 若n首位是1(如12345), 那么有 `2346` 个(`[10000, 12345]`)
2. 若n的首位不是1(如23456), 那么有 `10000` 个(`[10000,19999]`)

对第二类问题
- 考虑 `> 3456` 中非最高位为1出现的个数
可以划分为两个区间 `[10000, 19999]`, `[3457, 9999]U[20001, 23456]`
对任意一个区间，后面4个数字，选择其中一个为1，其他三个都可以在0~9中任意选择，因此一共有 `2*4*10^3` 个1
- 考虑 `[1, 3456]` 中非最高位为1出现的个数
递归求 [1, 3456]中1出现的次数

```c++
#include <cmath>
#include <string>

using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    if (n <= 0) { return 0; }
    if (n < 10) { return 1; }

    string strnum = to_string(n);

    int highNum = strnum[0] - '0';
    int size = strnum.size();
    int withoutHigh = n - highNum * pow(10, size - 1);

    // 1. 统计首位为1出现次数:
    //    - 若n首位是1(如12345), 那么有 2346个
    //    - 若n的首位U不是1(如23456), 那么有 10000个
    int firstOneCount = highNum == 1 ? (withoutHigh + 1)
                        : pow(10, size-1);
    // 统计其他位为1的出现次数
    // 2. 大于 3456
    //    - 可以划分为两个区间，例如对 23456 划分为
    //      [10000, 19999], [3457, 9999]U[20001, 23456]
    //    - 对任意一个区间，后面4个数字，选择其中一个为1，其他三个都可以在0~9中任意选择，因此一共有 2*4*10^3 个1
    int otherOneCount = highNum * (size - 1) * pow(10, size - 2);

    // 3. 递归求 [1, 3456]中1出现的次数
    return firstOneCount + otherOneCount + countDigitOne(withoutHigh);
  }
};
```