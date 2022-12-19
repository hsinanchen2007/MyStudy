### 思路

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int e = x ^ y, cnt = 0;
        for (int i = 0; i < 32; ++i) {
            cnt += (e >> i) & 1;
        }
        return cnt;
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int e = x ^ y, cnt = 0;
        while (e) {
            if (e & 1) ++cnt;
            e >>= 1;
        }
        return cnt;
    }
};
```
