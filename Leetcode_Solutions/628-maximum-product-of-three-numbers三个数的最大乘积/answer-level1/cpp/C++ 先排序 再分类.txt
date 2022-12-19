```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=0,l=nums.size();
        for(int i=0;i<l;++i){
            if(nums[i]>=0) {
                mid=i;
                break;
            }
        }
        if(mid<=1)return nums[l-1]*nums[l-2]*nums[l-3];
        else return max(nums[0]*nums[1]*nums[l-1],nums[l-1]*nums[l-2]*nums[l-3]);
    }
};
```
先找到负数和非负数的分界点mid，再分类计算即可
