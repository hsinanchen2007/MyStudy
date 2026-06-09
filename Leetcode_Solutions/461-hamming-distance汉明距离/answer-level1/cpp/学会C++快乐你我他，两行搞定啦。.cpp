学会C++快乐你我他，两行搞定啦。
```c++ []
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<sizeof(int)<<3> r(x^y);
        return r.count();
    }
};
```
