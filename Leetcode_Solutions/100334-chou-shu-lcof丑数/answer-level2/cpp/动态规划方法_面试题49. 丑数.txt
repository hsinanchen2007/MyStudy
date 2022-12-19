### 解题思路
    /*
     * 方法 动态规划（Dynamic Program）
     * 丑数的生成公式是：uglyNum = 2^x * 3^y * 5^z
     * 即x=y=z=0时，uglyNum = 1，
     * x = y = z = 1时，生成2,3,5等
     * 生成过程是先生成小的数，
     * 再在小的数的基础上生成后面的数。
     * 使用三个指针p2,p3,p5所对应的数值表示丑数，
     * 即每次都为vec[i] = min(vec[p2]*2, vec[p3]*3, vec[p5]*5)
     * 如果vec[i]==vec[p2/3/5]*2/3/5，对应的将p2/3/5加一
     * 第n个数即vec[n-1]
     * */

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
    std::vector<int> vec(n);
    int d2 = 0, d3 = 0, d5 = 0;
    vec[0] = 1;

    for (int i = 1; i < n; i++) {
        vec[i] = std::min(vec[d2] * 2, std::min(vec[d3] * 3, vec[d5] * 5));
        if (vec[i] == vec[d2] * 2) d2++;
        if (vec[i] == vec[d3] * 3) d3++;
        if (vec[i] == vec[d5] * 5) d5++;
    }

    return vec[n - 1];
    }
};
```