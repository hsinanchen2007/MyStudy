### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int flag=0;
            for(int j=1;j<nums.size();j++)
                if(nums[(i+j)%nums.size()]>nums[i]){
                    ans.push_back(nums[(i+j)%nums.size()]);
                    flag=1;
                    break;
                }
            if(!flag)ans.push_back(-1);
        }
        return ans;
    }
};
```