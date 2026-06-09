### i

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            sum += (n & 1);
            n >>= 1;
        }
        return sum;
    }
};
```

### ii
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            n &= n-1;
            res++;
        }
        return res;
    }
};
```