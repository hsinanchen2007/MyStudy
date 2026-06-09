### 解题思路
回溯法
![捕获.JPG](https://pic.leetcode-cn.com/08a3fe638ee280ca0047241312592d3ab9b9178d868dc72a33b184cec34bcfcc-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtrack(int k, int n, vector<int> record, int last) {
        if (k == 0) {
            if (n == 0) {
                result.push_back(record);
            }
            return;
        }
        for (int i = last + 1; i <= min(9, n); i++) {
            record.push_back(i);
            backtrack(k - 1, n - i, record, i);
            record.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> record;
        backtrack(k, n, record, 0);
        return result;
    }
};
```