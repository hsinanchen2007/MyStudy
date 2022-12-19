![捕获.PNG](https://pic.leetcode-cn.com/999c81a332819ba90f803f830a66ccf70e74fc89a1d7ce0959678419f938a793-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        int i = 1, sum = 0;
        sumcore(k, n, sum, temp, result, i);
        return result;
    }

    void sumcore(int k, int n, int sum, vector<int> temp, vector<vector<int>> &result, int iter) {
        if (temp.size() == k) {
            if(sum == n)
                result.push_back(temp);
            return;
        }
        for (int i = iter; i < 10; ++i) {
            temp.push_back(i);
            if (sum + i <= n)
                sumcore(k, n, sum + i, temp, result, i + 1);
            else
                return;
            temp.pop_back();
        }
    }
};
```