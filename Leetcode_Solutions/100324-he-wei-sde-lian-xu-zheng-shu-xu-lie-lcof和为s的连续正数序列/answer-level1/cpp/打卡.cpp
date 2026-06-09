### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int gap = 1;
        while (gap * (gap + 1)/2 < target) {
            vector<int> tmp;
            if ((target - gap * (gap + 1) / 2) % (gap + 1) ==0) {
                int x = (target - gap * (gap + 1)/2) / (gap + 1);
                for(int i = x; i < x+gap+1; i++) {
                    tmp.push_back(i);
                }
                res.emplace_back(tmp);
            }
            gap += 1;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
```