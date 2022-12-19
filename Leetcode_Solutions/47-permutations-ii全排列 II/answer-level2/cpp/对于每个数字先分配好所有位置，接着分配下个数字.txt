### 解题思路
对于每个数字先分配好其能出现位置的所有组合，然后分配下个数字，每全部分配完一次即得到一个排列。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto n: nums)
            ++ps[n];

        int n = nums.size();
        flags = vector<int>(n, 0);
        vector<int> per(n);
        permute(ps.begin(), per, 0, 0);
        return res;
    }

    void permute(map<int, int>::iterator beg, vector<int>& per, int start, int k)
    {
        if(beg == ps.end())
            res.push_back(per);

        auto next = beg;
        ++next;
        for(int i=start;i<flags.size();++i)
        {
            if(flags[i] == 0)
            {
                flags[i] = 1;
                per[i] = beg->first;
                if(k + 1 == beg->second)
                    permute(next, per, 0, 0);
                else
                    permute(beg, per, i+1, k+1);

                flags[i] = 0;
            }
        }
    }

    vector<vector<int>> res;
    map<int, int> ps;
    vector<int> flags;
};
```