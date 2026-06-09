```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;

        reverse(matrix.begin(), matrix.end());
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
```

也可以先转置，再翻转