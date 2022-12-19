### 解题思路
要注意x/y可能为1情况，此时要排除

### 代码
```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if (x < 0 || y < 0 || bound <= 0) {
            return vector<int> ();
        }
        unordered_set<int> st;
        TotalPowerInterger(x, y, 0, 0, 1, 1, bound, st);
        return vector<int>(st.begin(), st.end());        
    }
    void TotalPowerInterger(int x, int y, int i, int j, int x_val, int y_val,
                            const int bound, unordered_set<int>& res) {
       if (x_val + y_val > bound) {
           return;
       }
        res.insert(x_val + y_val);
        if (x != 1)
        TotalPowerInterger(x, y, i + 1, j, x_val * x, y_val, bound, res);
        if (y != 1)
        TotalPowerInterger(x, y, i, j + 1, x_val, y_val * y, bound, res);
    }
};
```