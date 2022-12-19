```C++ []
class Solution {
public:
    int update(const string& target, int i, const string& source) {
        int j = 0;
        while (i < target.size() && j < source.size()) {
            if (target[i] == source[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return i;
    }
    int shortestWay(string source, string target) {
        int i = 0;
        int res = 0;
        while (i < target.size()) {
            ++res;
            int t = update(target, i, source);
            if (t == i) return -1;
            i = t;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3a37d5263cd739b517cfe32902ca686645e4daead864869cc3e7fb0d4e06aae4-image.png)
