
### 代码

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;

        int sum = 0;
        for(int a:A)
        {
            sum = (sum * 2 + a) % 5;
            res.push_back(sum == 0);
        }

        return res;
    }
};
```