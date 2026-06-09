```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN, f = INT_MAX;
        
    for (int i = 0; i < nums.size(); ++i){
        f = min(f, nums[i]);//The smallest number that appears
        if (nums[i] > first){//-2147483648
            third = second, second = first, first = nums[i];
        }else if (nums[i] > second && nums[i] < first){
            third = second, second = nums[i];
        }else if (nums[i] > third && nums[i] < second) {
            third = nums[i];
        }
    }
    return second > third && third >= f ? third : first;
}
};
```
