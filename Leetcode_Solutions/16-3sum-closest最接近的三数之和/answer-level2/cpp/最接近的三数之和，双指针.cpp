和三树之和思路是一样的，都是用双指针，只不过这个题目是要求最接近于target的三数之和，那么就是判断条件之后的操作语句改为判断最小值和替换最小值的语句就可以了，总体思路是差不多的
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        if(nums.size()<3) return target;
        int min = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right] == target) return target;
                else if(nums[i]+nums[left]+nums[right] < target){
                    int temp = target - nums[i] - nums[left] - nums[right];
                    if(temp<min){
                        min = temp;
                        res = nums[i] + nums[left] + nums[right];
                    }
                    left++;
                }
                else if(nums[i]+nums[left]+nums[right] > target){
                    int temp = nums[i] + nums[left] + nums[right] - target;
                    if(temp<min){
                        min = temp;
                        res = nums[i] + nums[left] + nums[right];
                    }
                    right--;
                }
            }
        }
        return res;
    }
};
```
