```C++ []
class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        if (start == end) return true;
        int x1 = 0;
        int x2 = 0;
        for (auto c : start) x1 += c == 'X';
        for (auto c : end) x2 += c == 'X';
        if (x1 != x2 || x1 == 0 || x2 == 0) return false;
        int N = start.size();
        int l1 = 0;
        int l2 = 0;
        int r1 = 0;
        int r2 = 0;
        for (int i = 0; i < N; ++i) {
            l1 += start[i] == 'L';
            l2 += end[i] == 'L';
            r1 += start[i] == 'R';
            r2 += end[i] == 'R';
            if (l1 > l2 || r1 < r2) return false;
        }
        return true;
    }
};
```

![image.png](https://pic.leetcode-cn.com/40c418a065b7ff66f8f4671130a37a6a8a867e79650040f301133ea819d639d7-image.png)
