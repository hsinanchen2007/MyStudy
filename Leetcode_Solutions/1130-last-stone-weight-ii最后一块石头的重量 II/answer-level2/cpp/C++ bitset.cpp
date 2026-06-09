## 思路
讲一下思路，比如有个数组 `[a,b,c]`，我们每次选出两个数字，`a, b` 得到 `a-b`，然后再将新数字放入(0 忽略)。之后再选出两个数字, `c`，和，`a-b`, 得到 `c+b-a`。最后的到的结果实际上是对数组中的每个数字进行加减运算得到的, 其实就是一个加减多项式的最优解问题。一共结果有 $2^(n-1)$种，我们求出其中结果最好的就行了。不过数据太大，直接枚举肯定不行, 不过可以使用 `bitset` 来做。

## 代码

```c++ [-C++]
#include <bitset>
using namespace std;

const int bound = 40000;
const int capacity = 80000;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        bitset<80000> F;
        F.reset();
        F[bound] = 1;

        for (int stone : stones) {
            F = (F << stone) | (F >> stone);
        }
        for (int i = 0; i < 30000; i++) {
            if (F[bound+i]) return i;
        }
        return -1;
    }
};
```

## 讲解
是不是非常简单，我们一开始推断数据范围，然后定义了一个 `bitset`, 我们选取中间位置为 $0$，想做向右分别代表一个数字。`F` 一开始设为 $0$，然后不断读取数字，对原来的 `F` 进行左移和右移个单位，表示对原来的结果进行加减相关个单位。这样我们就只用一次遍历就得到了所有的结果，之后就是从 $0$ 开始找一个最小值。
