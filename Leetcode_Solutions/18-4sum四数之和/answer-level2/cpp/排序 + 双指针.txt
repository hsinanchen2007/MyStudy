### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vv;
        int len = nums.size();
        if( len < 4 ) return vv;

        sort(nums.begin(), nums.end());

        int i, j, m, n, sum4;
        for(i=0; i<len-3; i++)
        {
            for(j=i+1; j<len-2; j++)
            {
                m = j+1, n = len-1;
                while( m < n )
                {
                    sum4 = nums[i] + nums[j] + nums[m] + nums[n];
                    if( sum4 == target )
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[m]);
                        v.push_back(nums[n]);
                        vv.push_back(v);
                        m++, n--;
                    }
                    else if( sum4 > target ) n--;
                    else m++;
                }
            }
        }
        sort(vv.begin(),vv.end());
        vv.erase(unique(vv.begin(),vv.end()), vv.end());
        return vv;
    }
};
```