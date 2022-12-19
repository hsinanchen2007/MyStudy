### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> res;
        int val = num;
        while(val) {
            int tail = val % 10;
            val = val / 10;
            res.push_back(tail);
        }
        reverse(res.begin(), res.end());
        int i = 1;
        while(i < res.size() && res[i] <= res[i-1]) {
            ++i;
        }
        if ( i == res.size()) {
            return num;
        }
        int max_num = res[i];
        int index = i;
        for(; i < res.size(); ++i) {
            if (res[i] >= max_num) {
                max_num = res[i];
                index = i;
            }
        }
        int j = 0;
        for(; j < index; ++j) {
            if (res[j] < max_num) {
                break;
            }
        }
        swap(res[j], res[index]);
        int result = 0;
        for(int i = 0; i < res.size(); ++i) {
            result = result * 10 + res[i];
        }
        return result;
    }
};
```