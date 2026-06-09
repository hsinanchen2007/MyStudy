![image.png](https://pic.leetcode-cn.com/cd800f5eb7bb3e140012f724457bc716a9406b40e03ef0dc858e6748e4a73d1f-image.png)

总之 去重 = sort + 下标移动

```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        answer(output, nums, tmp,0); 
        return output;
    }
    
    void answer(vector<vector<int>>& result,vector<int>& nums,vector<int>& tmp,int level){
        if(level <= nums.size()){
            result.push_back(tmp);
        }
        
        for(int j=level;j<nums.size();j++){
            tmp.push_back(nums[j]);
            answer(result,nums,tmp,j+1);
            while(j<nums.size()-1 and nums[j] == nums[j+1]){
                j++;
            }
            tmp.pop_back();
        }       
    }
    
};
```
