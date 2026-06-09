### 解题思路
1、第一个想法就是散列表
2、但是官方非常巧妙，利用数组自身的索引来标记是否存在。

### 代码

```cpp
class Solution {
public:
    // // 散列表
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     std::vector<int> temp_vec(nums.size());
    //     for(int i=0;i<nums.size();++i){
    //         int temp = nums[i]-1;
    //         temp_vec[temp] += 1;
    //     }
    //     vector<int> output;
    //     for(int i=0;i<temp_vec.size();++i){
    //         if(temp_vec[i] == 0){
    //             output.push_back(i+1);
    //         }
    //     }
    //     return output;
        // 原地操作
        for(int i=0;i<nums.size();++i){
            int index = abs(nums[i])-1;
            nums[index] = nums[index] > 0 ?  -nums[index] : nums[index];
        }
        vector<int> output;
        for(int i=0;i<nums.size();++i){
            if(nums[i] > 0){
                output.push_back(i+1);
            }
        }
        return output;
    }
};
```