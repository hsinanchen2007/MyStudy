### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res; 
        vector<int> v;
        int i = 1;
        while(i <= (target + 1)/2)
        {
            int sum = 0;
            int add = i;
            while(sum < target)
            {
                v.push_back(add);
                sum = sum + add;
                add++;
            }
            if(sum != target)
            {
                v.clear();
            }
            else
            {
                res.push_back(v);
            }
            i++;
        }
        if(target == 1)
        {
            res.clear();
        }
        return res;
    }
};
```