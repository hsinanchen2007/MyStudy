### 解题思路
1.分别记录当前到达的最大值和之前的到达的最大值
2.如果达到当前的最大值，则更新，且跳数加1

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int current_max_index = nums[0];
        int pre_max_index = nums[0];
        int jump_min = 1;
        for(int i = 1 ; i< nums.size() ;i++){
            if(i > current_max_index){
                jump_min++;
                current_max_index = pre_max_index;
            }
            if(pre_max_index < i+nums[i]){
                pre_max_index = i+nums[i];
            }
        }
        return jump_min;
    }
};
```