### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size()+1);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(v[nums[i]]!=0){
                ans.push_back(nums[i]);
            }
            else
                v[nums[i]]=nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            if(v[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```