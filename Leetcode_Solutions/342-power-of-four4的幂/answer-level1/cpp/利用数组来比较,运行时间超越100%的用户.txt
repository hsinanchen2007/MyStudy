## 解题思路
因为int的范围为2^-31到2^31-1,故对应范围内的4的幂储存在一个数组中,然后只需要判断num是否在数组中即可,运行时间超越100%的用户

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        vector<double>arr;
        for (int i = -15; i <= 15; i++)
            arr.push_back(pow(4, i));
        if (count(arr.begin(), arr.end(), (double)num))
            return 1;
        else
            return 0;
    }
};
```