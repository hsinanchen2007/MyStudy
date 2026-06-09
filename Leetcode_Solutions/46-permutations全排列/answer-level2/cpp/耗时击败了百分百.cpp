### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        // 这个简单
        int flag = 1;
        int maxi = 0;
        int maxj = 0;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while(flag)
        {
            for(int i = nums.size()-2;i>=0;i--)
            {
                if(nums[i] < nums[i+1])
                {
                    maxi = i;
                    break;
                    //flag = 0;
                }
            }
            for(int i = nums.size()-1;i>=0 ;i--)
            {
                if(nums[maxi] < nums[i])
                {
                    maxj = i;
                    break;
                }
            }
            
            if(maxi == 0 && maxj == 0) flag = 0;
            else {
              swap(nums[maxi],nums[maxj]);
              reverse(nums.begin()+maxi+1,nums.end());
              res.push_back(nums);
            }
             maxi = 0;
             maxj = 0;
        }
       return res;
    }
};
```