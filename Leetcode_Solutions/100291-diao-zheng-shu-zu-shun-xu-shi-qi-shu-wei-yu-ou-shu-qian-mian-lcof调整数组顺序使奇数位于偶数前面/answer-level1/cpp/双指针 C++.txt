```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int lo =0, hi=nums.size()-1; //头尾指针
        while(lo<hi){
            //向中间收缩，遇到奇偶反序则调换
            while(lo<hi && nums[lo]%2==1) lo++;
            while(lo<hi && nums[hi]%2==0) hi--;
            swap(nums[lo],nums[hi]);
        }
        return nums;
    }
};
```
