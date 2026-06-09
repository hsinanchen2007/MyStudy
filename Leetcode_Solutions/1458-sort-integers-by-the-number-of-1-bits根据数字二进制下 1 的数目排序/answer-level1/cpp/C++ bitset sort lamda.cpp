![图片.png](https://pic.leetcode-cn.com/8c1aaf2c3c7c3e6584d962fbca04f1a83596029fcbd01efdd353ed3cc78bd042-%E5%9B%BE%E7%89%87.png)

```
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) -> bool {
            bitset<32> bsa(a);
            bitset<32> bsb(b);
            size_t ca = bsa.count();
            size_t cb = bsb.count();
            if (ca != cb) {
                return ca < cb;
            } else {
                return a < b;
            }
        });
        
        return arr;
    }
};
```

