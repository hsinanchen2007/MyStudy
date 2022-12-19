### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<vector<int>> ans;
        if(nums.size()==0)return ans;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(auto n : nums){
            while(hash[n]!=0&&hash[target-n]!=0){
                vector<int> v;
                v.push_back(n);
                hash[n]--;
                if(hash[target-n]!=0){
                    v.push_back(target-n);
                    hash[target-n]--;
                }
                else{
                    break;
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};
```