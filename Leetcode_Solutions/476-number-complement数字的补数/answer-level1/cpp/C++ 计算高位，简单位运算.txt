```
class Solution {
public:
    const int N = sizeof(int) * 8;
    // 二分法找到最高位
    int findHighBit(long long n) {
        int left = 0;
        int right = N;
        while (left < right) {
            int mid = left + (right - mid + 1) / 2;
            if (n >= ((long long)1 << mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    int findComplement(int num) {
        int high_mask = ((long long)1 << (findHighBit(num) + 1)) - 1;
        return high_mask ^ num;
    }
};
```

![image.png](https://pic.leetcode-cn.com/f649c77623abdb4e4d708a74f2a735a1c60638f323fa97583089cbb4be62b196-image.png)
