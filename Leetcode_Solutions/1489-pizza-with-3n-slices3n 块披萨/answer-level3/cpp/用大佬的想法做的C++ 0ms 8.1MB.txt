### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int need = n / 3;
        int ret = 0;
        for (int i = 0; i < need; i++) {
            int max_pos = max_element(slices.begin(), slices.end()) - slices.begin();
            int max_left = (max_pos + slices.size() - 1) % slices.size();
            int max_right = (max_pos + slices.size() + 1) % slices.size();
            cout << max_left << ' ' << max_pos << ' ' << max_right << endl;
            int dis = slices[max_left] + slices[max_right] - slices[max_pos];
            ret += slices[max_pos];
            slices[max_pos] = dis;
            vector<int> v = {max_left, max_right};
            sort(v.rbegin(), v.rend());
            for (auto d : v)
                slices.erase(slices.begin() + d);
        }
        return ret;

    }
};
```