### 解题思路
具体参考：
https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
https://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-dan-ni-er-xue-bi/

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector <int>> result;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]>0)
            {
                break;
            }
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }  

            int k=nums.size()-1;
            int j=i+1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }   
                else if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else
                {
                    while(j<k&&nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    while(j<k&&nums[k]==nums[k-1])
                    {
                        k--;
                    }
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                 }
            }
        }

        return result;  
    }
};
```