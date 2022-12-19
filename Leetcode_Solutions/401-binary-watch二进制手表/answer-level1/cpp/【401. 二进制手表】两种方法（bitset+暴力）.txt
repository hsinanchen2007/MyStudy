### 思路一：bitset
整数转为二进制数，使用count统计二进制位中1的个数。

### 代码

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                } 
            }
        }
        return res;
    }
};
```

### 思路二：暴力

### 代码
```c++
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (count1(h) + count1(m) == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                } 
            }
        }
        return res;
    }

    int count1(int n) {
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            ++res;
        }
        return res;
    }
};
```
