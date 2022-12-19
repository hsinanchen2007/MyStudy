```cpp
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, maxx = 0;
        for (int i = 0, sz = light.size(); i < sz; ++i) {
            maxx = max(maxx, light[i]);
            if (maxx == i + 1) res++;
        }
        return res;
    }
};
```
