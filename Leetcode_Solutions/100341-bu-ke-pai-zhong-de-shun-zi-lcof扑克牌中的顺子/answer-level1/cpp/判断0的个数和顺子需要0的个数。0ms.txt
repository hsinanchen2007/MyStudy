```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=4,tmp=0; //tmp为需要0的数量
        for(;i>0;i--){
            if(nums[i-1]==0)//跳出后，i为0的数量
                break;
            if(nums[i]==nums[i-1])//相等不为顺子
                return 0;
            tmp+=nums[i]-nums[i-1]-1;//两个数之间需要0的数量
                                    // 相邻的两个数不需要0
        }
        return tmp<=i;
    }
};
```
