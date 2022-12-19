排序后遍历序列, 固定x, 双指针寻找y和z (y+z = -x)
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        if(nums.front()>0 || nums.back()<0) return {};
        vector<vector<int> > ret;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int fix = -nums[i];
            int l = i+1, h = nums.size()-1;
            while(l<h){
                if(nums[l]+nums[h]==fix){
                    while(l<h && nums[l] == nums[l+1]) l++;
                    while(l<h && nums[h] == nums[h-1]) h--;
                    ret.push_back(vector<int>{nums[i],nums[l],nums[h]});
                    l++;h--;
                }
                else if(nums[l]+nums[h]<fix) l++;
                else h--;
            }
        }
        return ret;
    }
};
```
