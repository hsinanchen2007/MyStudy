### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();

        int res = nums[0];  // 先用地一个元素初始化结果
        int appearTimes = 1;    // 用来计数

        for(int i = 1; i < len; ++i){
            if(appearTimes == 0){
                res = nums[i];
                appearTimes = 1;
            }
            else if(res == nums[i]){
                ++appearTimes;
            }
            else{
                --appearTimes;
            }
        }

        return res;
    }
};
```