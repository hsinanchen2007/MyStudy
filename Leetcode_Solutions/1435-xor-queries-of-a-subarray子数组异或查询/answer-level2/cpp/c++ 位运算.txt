### 解题思路
利用位运算公式 a ^ b ^ a = b
1. 统计[0, i]范围的xor异或值
2. query[i, j] = query(0, j) xor query(0, i - 1)

### 代码

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        if (arr.empty()) {
            return vector<int>();
        }
        if (arr.size() == 1) {
            return vector<int>(queries.size(), arr[0]);
        }
        vector<int> xors(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0) {
                xors[0] = arr[0];
            } else {
                xors[i] = arr[i] ^ xors[i - 1];
            }
        }
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (start == end) {
                res[i] = arr[start];
                continue;
            }
            if (start == 0) {
                res[i] = xors[end];
                continue;
            }
            res[i] = xors[end] ^ xors[start - 1];
        }
        return res;
    }
};
```