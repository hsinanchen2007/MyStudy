### 解题思路
dfs

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    vector<vector<int>> combinationSum3(int k, int n) {
        for(int i = 1; i <= 9; ++i) {
            dfs(i, n, 0, k);
        }
        return res;
    }

    void dfs(int index, int current, int count, int k) {
        if (index > 9) {
            return;
        }
        ++count;
        if (count > k) {
            return;
        }
        current = current - index;
        item.push_back(index);
        if (count == k) {
            if ( current == 0) {
                res.push_back(item);
                //item.pop_back();
                //return;
            }
            item.pop_back();
            return;
        }
        for(int i = index+1; i <= 9; ++i) {
            dfs(i, current, count, k);
        }
        item.pop_back();
        return;
    }
};
```