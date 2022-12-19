### 解题思路
把二维矩阵变一维，然后排序，返回第k个元素


```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> result;
        for (int i = 0; i < matrix.size();i++){
            for (int j = 0; j < matrix.size();j++){
                result.push_back(matrix[i][j]);
            }
        }

        sort(result.begin(), result.end());

        return result[k - 1];
    }
};
```

插入排序
### 代码

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> result;
        for (int i = 0; i < matrix.size();i++){
            for (int j = 0; j < matrix.size();j++){
                int index = lower_bound(result.begin(), result.end(), matrix[i][j]) - result.begin();
                result.insert(result.begin() + index, matrix[i][j]);
            }
        }
        return result[k - 1];
    }
};
```