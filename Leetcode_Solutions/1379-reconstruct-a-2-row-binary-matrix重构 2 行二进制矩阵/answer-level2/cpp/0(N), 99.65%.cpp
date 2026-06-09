### 解题思路
colsum = 2 --> [1, 1]
colsum = 1 --> [1, 0] 或者[0, 1]
colsum = 0 --> [0, 0]

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int cols = (int)colsum.size();
        vector<vector<int>> res(2, vector<int>(cols, 0));
        for (int i = 0; i < cols; i++) {
            if (colsum[i] == 0 || colsum[i] == 1) continue;
            res[0][i] = 1;
            res[1][i] = 1;
            upper--;
            lower--;
            // std::cout << "upper: " << upper << ", lower: " << lower << std::endl;
        }
        for (int i = 0; i < cols; i++) {
            if (colsum[i] == 0 || colsum[i] == 2) continue;
            if (upper > 0) {
                res[0][i] = 1;
                upper--;
            } else {
                res[1][i] = 1;
                lower--;
            }
            // std::cout << "upper: " << upper << ", lower: " << lower << std::endl;
        }
        if (upper != 0 || lower != 0) {
            res.clear();
            return res;
        }

        return res;
    }
};
```