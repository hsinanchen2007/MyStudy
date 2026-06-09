经过排序，for循环中的i应该等于nums[i]，所以只要找到满足 i!=nums[i] 的i即可
如果缺失的是n，返回nums[nums.size()-1]+1即可
```
Code fence
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min = nums[0];
        int max = nums[nums.size() -1 ];
        for(int i = 0 ; i <= nums[nums.size()-1];++i){
            if(nums[i] != i) return i;
        }
        return nums[nums.size()-1] + 1;
    }
};
```