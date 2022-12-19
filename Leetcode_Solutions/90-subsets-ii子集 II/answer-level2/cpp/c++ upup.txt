### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.9 MB
, 在所有 C++ 提交中击败了
99.50%
的用户
### 代码

```cpp
class Solution {
public:
vector<vector<int>> ans;
int N;
    void dps(vector<int>& nums, vector<int>& vec, int idx)
    {
        ans.push_back(vec);
        
        for (int i = idx; i<N; i++)
        {
            // add
            if (i>idx && nums[i]==nums[i-1]) continue;

            vec.push_back(nums[i]);
            dps(nums,vec,i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // add
        sort(nums.begin(), nums.end());
        
        vector<int> vec;
        this->N = nums.size();
        dps(nums, vec, 0);
        return ans;
    }
};
```