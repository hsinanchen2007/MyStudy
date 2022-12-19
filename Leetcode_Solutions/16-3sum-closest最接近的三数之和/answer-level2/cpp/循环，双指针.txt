### 解题思路


### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 比三数字之和要简单思路大体相同
        int len = nums.size();
        if(len < 3) {
            for(int i=1; i<len; ++i) nums[0] += nums[i];
            return nums[0];
        }
        sort(nums.begin(), nums.end()); // 排序
        // -4 -1 1 2
        int rst = 0;
        // target
        int border[2] = {INT_MIN, INT_MAX}; //记录左右两面的差值
        int now_circle;
        for(int i=0; i<len; ++i)
        {
            int low = i+1;
            int high = len -1;
            while(low < high){
                now_circle = nums[i] + nums[low] + nums[high]; // 当前三数据的值
                if(now_circle == target) return now_circle;
                if(now_circle < target){
                    if(now_circle > border[0]){
                        border[1] = (target + target)- now_circle;
                        border[0] = now_circle;
                        rst = now_circle;
                    }
                    ++low;
                } 
                else if(now_circle > target){
                    if(now_circle < border[1]){
                        border[0] = target + target - now_circle;
                        border[1] = now_circle;
                        rst = now_circle;
                    }
                    --high;
                }
            }
        }
        return rst;
    }
};
```