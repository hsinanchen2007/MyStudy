### 代码
```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = { 0 };
        for (int a : arr) ++cnt[a];
        for (int i = 500; i > 0; --i)
            if (i == cnt[i]) return i;
        return -1;
    }
};
```