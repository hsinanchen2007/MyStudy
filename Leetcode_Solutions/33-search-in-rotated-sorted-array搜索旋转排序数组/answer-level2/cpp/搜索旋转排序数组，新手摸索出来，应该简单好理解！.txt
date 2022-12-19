看了其他答案还是有一点懵，这个是自己理解调试出来的。
看到题目基本都知道用二分法，但是旋转后怎么分是个问题。
这里关键是明确目标数是在左侧还是右侧，然后根据约束条件进行二分处理，直接上代码，大家多多指教。
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        bool onLeft = nums.size() > 0 && nums[0] <= target; // 标记目标数可能在旋转后的左侧还是右侧
        while(L <= R){ 
            int mid = (L + R) / 2;  // 二分查找
            if(nums[mid] == target){
                return mid;
            }
            if(onLeft){
                // (附加条件：中间数属于左侧时，才移动左游标，否则如果把左游标移动到右侧，与上述onLeft结果矛盾)
                if(nums[mid] < target && nums[mid] >= nums[0]){ 
                    L = mid + 1;
                }else{
                    R = mid - 1;
                }    
            }else{
                // (附加条件：中间数属于右侧时，才移动右游标，否则如果把右游标移动到左侧，与上述onLeft结果矛盾)
                if(nums[mid] > target && nums[mid] < nums[0]){
                    R = mid - 1;
                }else{
                    L = mid + 1;
                }
            }
        }
        return -1;
    }
};
```
