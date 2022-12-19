```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                for(int j=i+1;j<nums.size();++j){
                    if(nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        return;
    }
};
```
遍历数组，若出现0，则往后搜索到第一个非0数，两者交换即可
