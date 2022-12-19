
### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        //用help1记录nums[i]左边所有项的乘积（nums[0]左边的项的乘积为1）
        //用help2记录nums[i]右边所有项的乘积（nums.back()右边的项的乘积为1）
        vector<int> help1,help2;

        help1.push_back(1);
        int sum=1;
        for(int i=0;i<nums.size()-1;i++)
            help1.push_back(sum*=nums[i]);
        sum=1;
        for(int i=nums.size()-1;i>0;i--)
            help2.push_back(sum*=nums[i]);
        reverse(help2.begin(),help2.end());
        help2.push_back(1);

        //output[i]为nums[i]左右所有项的乘积
        for(int i=0;i<nums.size();i++)
            output.push_back(help1[i]*help2[i]);
        
        return output;
    }
};
```