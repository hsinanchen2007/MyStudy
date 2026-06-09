## 思路
每行从后向前遍历。
### 代码
空间复杂度：O(k)
```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0 || j == i) {
                    res[j] = 1;
                } else {
                    res[j] = res[j] + res[j - 1];
                }
            }
        }
        return res;
    }
};
```
#### 另一种写法（击败100%）
```c++
空间复杂度：O(k)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i < rowIndex + 1; ++i) {            
            for (int j = i; j > 0; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
```

