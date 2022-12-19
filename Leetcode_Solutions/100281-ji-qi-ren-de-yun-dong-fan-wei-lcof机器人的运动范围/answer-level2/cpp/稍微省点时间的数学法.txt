首先来看两幅图：
![1.png](https://pic.leetcode-cn.com/56297e76ec9ed2bc7039bc809b2eaa51b819f861ea855c4404cb0b62969cfe08-1.png)
![2.png](https://pic.leetcode-cn.com/7ef322e7897ad6414f802345f3e1341058e6eaa0940ea6618729546e1985516a-2.png)

从图1可以看出每个10x10的区域有一个三角形。三角形随着x坐标或者y坐标的增大逐渐变小，变小是由x、y坐标十位增大引发实际的k变小导致的。（幸好m和n最大值都是100，不然还要更麻烦一点。）因此对每个10x10的区域我们可以求k' = k - x / 10 - y / 10时能走到的格子个数，这个问题很简单就是一个分段函数。至于那些小于10x10的区域个数不多直接数就行了。

从图1和图2可以看出当k比较小时就到不了右面或者下面的区域了，这个范围很好判定就是k'是否大于等于9。如果上下两行第一个区域无法相连，那后面的更不可能相连，因为后面的区域k'更小。
<br>
```cpp
#include <cassert>

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int res = 0;

        for (int i = 0; i < m; i += 10) {
            bool reachableNextLine = false;

            for (int j = 0; j < n; j += 10) {
                int k1 = k - (i / 10) - (j / 10);
                if (k1 < 0)
                    break;

                int temp;
                if (i + 10 <= m && j + 10 <= n)
                    temp = countQuick(k1);
                else
                    temp = countSlow(min(m - i, 10), min(n - j, 10), k1);

                //cout << i << ' ' << j << ": " << temp << endl;

                res += temp;

                if (!reachable(k1))
                    break;

                reachableNextLine = true;
            }

            if (!reachableNextLine)
                break;
        }

        return res;
    }

private:
    // 10 x 10格子k能到达的格子个数。
    static inline int countQuick(int k) noexcept {
        assert(k >= 0);

        if (k <= 9)
            return (k + 1) * (k + 2) / 2;
        else if (k < 18)
            return 55 + (k - 9) * (28 - k) / 2;
        else
            return 100;
    }

    // m x n格子k能到达的格子个数。
    static inline int countSlow(int m, int n, int k) noexcept {
        assert(m < 10 || n < 10);

        int res = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + j > k)
                    break;

                ++res;
            }
        }

        return res;
    }

    // 10 x 10格子k是否能到达右面或者下面的邻居。
    static inline bool reachable(int k) noexcept {
        return k >= 9;
    }
};

```