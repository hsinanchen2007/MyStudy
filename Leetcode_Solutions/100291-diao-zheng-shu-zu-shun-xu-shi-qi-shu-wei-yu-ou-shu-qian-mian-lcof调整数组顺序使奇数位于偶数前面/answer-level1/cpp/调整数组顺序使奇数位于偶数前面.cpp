利用仿函数进行定义规则

```
class Solution {
public:
    struct Cmp{
        bool operator()(int a){
            return a&1;
        }
    }cmp;
    
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            while(left < right && cmp(nums[left])){
                ++left;
            }
            while(left < right && !cmp(nums[right])){
                --right;
            }
            if(left < right){
                swap(nums[left],nums[right]);
            }
        }
        return nums;
    }
};
```
