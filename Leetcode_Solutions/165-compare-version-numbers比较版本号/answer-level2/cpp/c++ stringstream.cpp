```cpp
class Solution {
public:
    int compareVersion(const string &version1, const string &version2) {
        istringstream v1(version1 + ".");
        istringstream v2(version2 + ".");
        int d1 = 0;
        int d2 = 0;
        char dot = '.';
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};
```
