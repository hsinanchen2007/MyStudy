### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> a;
        vector<int> b(k,0);
        int i=0;
        while (i >= 0)
        {
            b[i]++;
            if (b[i] > n) i--;
            else if (i == k - 1) a.push_back(b);
            else
            {
                i++;
                b[i] = b[i - 1];
            }
        }
        return a;
    }
};
```