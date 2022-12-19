![image.png](https://pic.leetcode-cn.com/d2e2f9c10e63e64b98e21c52a052747c11056b0a8e4db22bf4f14be8402f7f16-image.png)

```cpp
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int temp = 0;
        for (int i = 1, j = 1;;++i) {
            for (j = 1;;++j) {
                temp = customfunction.f(i, j);
                if (temp == z) res.push_back(vector<int>{i, j});
                else if (temp > z) break;
            }
            if (j == 1) break;
            j = 1;
        }
        return res;
    }
};
```
