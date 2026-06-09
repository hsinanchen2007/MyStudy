### 解题思路
深度优先搜索

![image.png](https://pic.leetcode-cn.com/c327e60dd9cf950d16d2da7645394051c2cd066b7c3ca798cb70742013bb2920-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    void find(int st, int en, int k)
    {
        if(k <= 0)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = st; i <= en; i ++)
        {
            tmp.push_back(i);
            find(i + 1, en, k - 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        find(1, n, k);
        return ans;
    }
};
```