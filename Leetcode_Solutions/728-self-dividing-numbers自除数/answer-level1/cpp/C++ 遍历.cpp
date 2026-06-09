```c++
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> r;
        for (int n = left; n <= right; n++) {
            if (isSelfDividingNumbers(n)) r.push_back(n);
        }
        return r;
    }

    bool isSelfDividingNumbers(int n) {
        int a = n;
        while (a) {
            int r = a % 10;
            if (!r || (n % r)) return false;
            a /= 10;
        }
        return true;
    }
};
```