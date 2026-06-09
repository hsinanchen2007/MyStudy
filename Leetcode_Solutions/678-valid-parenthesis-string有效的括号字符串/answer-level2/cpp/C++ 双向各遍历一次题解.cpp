```C++ []
class Solution {
public:
    bool checkValidString(string s) {
        int bucket = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s[i] == '(') {
                ++bucket;
            } else {
                --bucket;
                if (bucket < 0) bucket = 0;
            }
        }
        if (bucket > 0) return false;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++bucket;
            } else {
                --bucket;
                if (bucket < 0) bucket = 0;
            }
        }
        return bucket == 0;
    }
};
```

![image.png](https://pic.leetcode-cn.com/05a8af1bc94abecd79232c34c7b035f36a900d2b8524c6e48ca095a2d646e15b-image.png)
