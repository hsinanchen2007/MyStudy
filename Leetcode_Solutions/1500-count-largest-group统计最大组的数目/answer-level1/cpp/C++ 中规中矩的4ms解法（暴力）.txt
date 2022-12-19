### 代码
```cpp
class Solution {
public:
    int help(long i) {
        int ret = 0;
        while (i) {
            ret += i % 10;
            i /= 10;
        }
        return ret;
    }

    int countLargestGroup(int n) {
        int cnt[41] = { 0 }, ans = 0, cntMax = 0;
        for (int i = 1; i <= n; ++i) ++cnt[help(i)];
        for (int i = 1; i <= 40; ++i) {
            if (cnt[i] > cntMax) {
                ans = 1;
                cntMax = cnt[i];
            }
            else if (cnt[i] == cntMax) ++ans;      
        }
        return ans;
    }
};
```