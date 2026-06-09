### 解题思路
使用hash表记录每个数值出现的个数
当新加入的数小于hash中的最大值时，新数对应的hash计数加一，最大数对应hash值减一，
当最大数个数为0时，从hash中删除

### 代码

```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) {
            return vector<int>();
        }

        if (k == arr.size()) {
            sort(arr.begin(), arr.end());
            return arr;
        }

        map<int, int> m;
        int cnt = 0;
        for (auto n : arr) {
            if (cnt < k) {
                ++m[n];
                ++cnt;
                continue;
            }
            auto last = m.rbegin();
            if (n < last->first) {
                ++m[n];
                --last->second;
                if (last->second <= 0) {
                    m.erase(last->first);
                }
            }
        }
        
        vector<int> res;
        for (auto& p : m) {
            res.insert(res.end(), p.second, p.first);
        }
        return res;
    }
};
```