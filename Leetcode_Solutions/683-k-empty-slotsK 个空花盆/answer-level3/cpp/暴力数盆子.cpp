### 解题思路
创建一个数组用于记录花盆的开放情况，然后每天看一下新开的花盆，往左数一数是否满足条件，往右数一数是否满足条件。这个理解比较直观，跟我们人去观察花盆的方法是一样的。

### 代码

```cpp
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        if (bulbs.empty() || K < 0)
            return -1;
        int len = bulbs.size();
        vector<int> flowers;
        flowers.resize(len, 0);
        
        K += 1;
        for (int i = 0; i < len; i++) {
            int f = bulbs[i] - 1;
            if (f - K >= 0 && flowers[f - K]) {
                bool status = true;
                for (int j = f - K + 1; j < f; j++)
                    if (flowers[j]) {
                        status = false;
                        break;
                    }
                if (status)
                    return i + 1;
            }
            if (f + K < len && flowers[f + K]) {
                bool status = true;
                for (int j = f + 1; j < f + K; j++)
                    if (flowers[j]) {
                        status = false;
                        break;
                    }
                if (status)
                    return i + 1;
            }
            flowers[f] = 1;
        }

        return -1;
    }
};
```