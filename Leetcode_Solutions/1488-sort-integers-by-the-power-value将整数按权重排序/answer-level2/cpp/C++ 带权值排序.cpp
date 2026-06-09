### 解题思路
1. 利用static数组 一次性计算出1~1000所有数的权值 并将1~1000按题目要求排序
2. 每次调用时遍历数组， 遇到符合条件的就将k减一直至k为0为止返回结果

### 代码

```cpp
class Solution {
public:
    static void inline Inc(int &x) {
        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = 3 * x + 1;
        }
    }
    int getKth(int lo, int hi, int k) {
        static short vs[1001] = {0};
        static short vc[1000] = {0};
        if (vs[2] == 0) {
            vs[2] = 1;
            for (int x = 3; x <= 1000; x++) {
                int tmp = 0;
                int tx = x;
                while (tx != 1) {
                    Inc(tx);
                    tmp++;
                }
                vs[x] = tmp;
            }
            for (int i = 1; i <= 1000; i++)
                vc[i - 1] = i;
            sort(vc, vc + 1000, [&vs](const auto x, const auto y) {
                return vs[x] < vs[y] || vs[x] == vs[y] && x < y;
            });
        }
        int ret = 0;
        for (auto x : vc) {
            if (x <= hi && x >= lo) {
                k--;
                // cout << x << endl;
                if (!k) {
                    ret = x;
                    break;
                }
            }
        }
        return ret;
    }
};
```