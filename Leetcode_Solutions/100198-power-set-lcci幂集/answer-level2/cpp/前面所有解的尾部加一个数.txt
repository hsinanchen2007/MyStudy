### 解题思路
在前面已经放入ret中的所有解的尾部加一个数
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> comp;
        ret.push_back(comp);
        for(int i=0;i<nums.size();i++)
        {
            int n = ret.size();
            for(int j=0;j<n;j++)
            {
                vector<int> comp(ret[j]);
                comp.push_back(nums[i]);
                ret.push_back(comp);
            }
        }
        return ret;
    }
};
```