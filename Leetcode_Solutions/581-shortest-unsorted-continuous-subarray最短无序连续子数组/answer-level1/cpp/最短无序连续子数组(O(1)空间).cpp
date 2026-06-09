**无序子数组中最小元素的正确位置可以决定左边界，最大元素的正确位置可以决定右边界。**
```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int i, j;
        int max_val = 0x80000000, min_val = 0x7fffffff;

        /*从头部找降序序列中的最小值*/
        bool ascending = 1;
        for(i = 0; i < len - 1; i++){
            if(nums[i] > nums[i+1])
                ascending = 0;
            if(!ascending)
                min_val = min(min_val, nums[i+1]);
        }

        /*从尾部找升序序列中的最大值*/
        ascending = 0;
        for(j = len - 1; j > 0; j--){
            if(nums[j] < nums[j-1])
                ascending = 1;
            if(ascending)
                max_val = max(max_val, nums[j-1]);
        }

        /*找到min_val的正确位置*/
        for(i = 0; i < len && nums[i] <= min_val; i++);

        /*找到max_val的正确位置*/
        for(j = len - 1; j >= 0 && nums[j] >= max_val; j--);

        int ans = j - i;
        return (ans > 0) ? ans + 1 : 0;
    }
};
```