![image.png](https://pic.leetcode-cn.com/001769e2dfcc630715be182d2bd78549790fd02e61915dbf9d58e761a6e2aded-image.png)

随手乱批的，娱乐一下。
利用constexpr，编译期计算，编译期就算完了。
不过代码很丑就是了。

```
constexpr bool isLegal(int num) {
    while (num > 0) {
        if (!(num%10)) {
            return false;
        }
        num/=10;
    }
    return true;
}

constexpr array<int, 10001> Pre1()
{
    array<int, 10001> temp{0};
    for (int i = 2; i <= 10000; i++) {
        for (int j = 1; j < i; j++) {
            if (isLegal(j) && isLegal(i - j)) {
                temp[i] = j;
                break;
            }
        }
    }
    return temp;
}

constexpr array<int, 10001> Pre2()
{
    array<int, 10001> temp{0};
    for (int i = 2; i <= 10000; i++) {
        for (int j = 1; j < i; j++) {
            if (isLegal(j) && isLegal(i - j)) {
                temp[i] = i - j;
                break;
            }
        }
    }
    return temp;
}

constexpr array<int, 10001> pre1 = Pre1();
constexpr array<int, 10001> pre2 = Pre2();

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        return { pre1[n], pre2[n] };
    }
};
```
