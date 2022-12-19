![image.png](https://pic.leetcode-cn.com/5fc19ae036e25e99585e5f90a674596d8a15b32b20cc9e299827ca6c34a638f0-image.png)

```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        int min = 1000001;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            int temp = arr[i + 1] - arr[i];
            if (temp < min) {
                min = temp;
                result = { { arr[i], arr[i + 1] } };
            } else if (temp == min) {
                result.emplace_back(vector<int>{ arr[i], arr[i + 1] });
            }
        }
        return result;
    }
};
```

